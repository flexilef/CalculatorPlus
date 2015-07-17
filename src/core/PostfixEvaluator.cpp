#include <cstdlib>
#include <iostream>
#include <stack>

#include "../../include/core/PostfixEvaluator.h"
#include "../../include/core/CalculatorUtil.h"
#include "../../include/core/MathTokenizer.h"

#include "../../include/core/CalculatorException.h"
#include "../../include/core/DomainException.h"
#include "../../include/core/SyntaxException.h"
#include "../../include/core/DivideByZeroException.h"



PostfixEvaluator::PostfixEvaluator(MemoryBank& mbref) : mBank(mbref)
{
    setAngleMode(MathUtil::DEGREES);
}

PostfixEvaluator::~PostfixEvaluator()
{
    //dtor
}

double PostfixEvaluator::evaluatePostfix(const std::string& postfix)
{
    return evaluate(postfix);
}

//helpers

double PostfixEvaluator::evaluate(const std::string& postfix)
{
    MathTokenizer tokenizer;
    tokenizer.setInput(postfix);

    std::stack<double> operandStack;
    std::stack<std::string> variableStack;
    Token currentToken;
    std::string currentTokenStr;

    int arity = -1;
    double result = 0;

    while(tokenizer.hasNext())
    {
        currentToken = tokenizer.getNextToken();
        currentTokenStr = currentToken.getString();

        if(currentToken.tokenType == Token::NUMBER)
        {
            double number = 0;

            if(currentTokenStr.find("..") != std::string::npos)
                throw CalculatorException("Syntax Error: invalid number: '" + currentTokenStr + "'");
            else
                number = atof(currentTokenStr.c_str());

            operandStack.push(number);
        }
        else if(currentToken.tokenType == Token::VARIABLE)
        {
            if(mBank.hasVariable(currentTokenStr))
            {
                double variableValue = mBank.getValueFromVar(currentTokenStr);
                operandStack.push(variableValue);
                variableStack.push(currentTokenStr);
            }
            else
            {
                variableStack.push(currentTokenStr);
            }
        }
        else if(currentToken.tokenType == Token::OPERATOR)
        {
            arity = CalculatorUtil::getArity(currentTokenStr);

            if(arity == 0)
            {
                if(currentTokenStr == "=")
                {
                    if(variableStack.empty())
                    {
                        throw CalculatorException("Syntax Error: assignment error");
                    }
                    //case 1: new var and number. ie. a=1
                    else if(!mBank.hasVariable(variableStack.top()) && variableStack.size() == 1)
                    {
                        double operand = 0;
                        std::string var;

                        if(!variableStack.empty())
                        {
                            var = variableStack.top();
                            variableStack.pop();
                        }
                        else
                            throw CalculatorException("Syntax Error: assignment error, missing variable");

                        if(!operandStack.empty())
                        {
                            operand = operandStack.top();
                            operandStack.pop();
                        }
                        else
                            throw CalculatorException("Syntax Error: assignment error, missing operand");

                        result = operand;
                        assignment(var, operand);
                        operandStack.push(result);
                    }
                    //case 2: old var and number. ie. a=1... a=2
                    else if(mBank.hasVariable(variableStack.top()) && variableStack.size() == 1)
                    {
                        std::string var;
                        double operand = 0;

                        if(!variableStack.empty())
                        {
                            var = variableStack.top();
                            variableStack.pop();
                        }
                        else
                            throw CalculatorException("Syntax Error: assignment error, missing variable");

                        if(!operandStack.empty())
                        {
                            operand = operandStack.top();
                            operandStack.pop();
                        }
                        else
                            throw CalculatorException("Syntax Error: assignment error, missing operand");

                        if(!operandStack.empty())
                            operandStack.pop();//pop the original value of the existing variable
                        else
                            throw CalculatorException("Syntax Error: assignment error, missing operand");

                        result = operand;
                        assignment(var, operand);
                        operandStack.push(result);
                    }
                    //case 3: new var and old var. ie. b=a where a=1 and b = new
                    //        old var and old var. ie. a=b where a=1 and b=2
                    else if(variableStack.size() >= 2)
                    {
                        double operand = 0;
                        std::string var;

                        if(!operandStack.empty())
                            operand = operandStack.top();
                        else
                            throw CalculatorException("Syntax Error: assignment error, missing operand");

                        while(!variableStack.empty())
                        {
                            var = variableStack.top();

                            //handles a=1+f errors where f is not assigned anything
                            if(!mBank.hasVariable(var) && variableStack.size() > 1)
                                throw CalculatorException("Syntax Error: assignment error: '" + std::string(var)
                                                          + "' is not assigned");

                            variableStack.pop();
                        }
                        while(!operandStack.empty())
                        {
                            operandStack.pop();
                        }

                        assignment(var, operand);
                        result = operand;
                        operandStack.push(result);
                    }
                }
            }
            else if(arity == 1)
            {
                double operand = 0;

                if(!operandStack.empty())
                {
                    operand = operandStack.top();
                    operandStack.pop();
                }
                else
                    throw CalculatorException("Syntax Error: missing operand");

                try
                {
                    if(currentTokenStr == "~")
                        result = mUtil.unaryNegation(operand);
                    else if(currentTokenStr == "!")
                        result = mUtil.factorial(operand);
                    else if(currentTokenStr == "%")
                        result = mUtil.percent(operand);
                    else
                        throw CalculatorException("PostfixEvaluator: evaluate(): invalid unary operator: " + std::string(currentTokenStr));
                }
                catch(MathException& e)
                {
                    throw CalculatorException(e.what());
                }

                operandStack.push(result);
            }
            else if(arity == 2)
            {
                double operand2 = 0;
                double operand1 = 0;

                //operand2 needs to be popped before operand1 for order to be right
                if(!operandStack.empty())
                {
                    operand2 = operandStack.top();
                    operandStack.pop();
                }
                else
                    throw CalculatorException("Syntax Error 1: missing operand(s)");

                if(!operandStack.empty())
                {
                    operand1 = operandStack.top();
                    operandStack.pop();
                }
                else
                    throw CalculatorException("Syntax Error 2: missing operand(s)");

                try
                {
                    if(currentTokenStr == "+")
                        result = mUtil.add(operand1, operand2);
                    else if(currentTokenStr == "-")
                        result = mUtil.subtract(operand1, operand2);
                    else if(currentTokenStr == "*")
                        result = mUtil.multiply(operand1, operand2);
                    else if(currentTokenStr == "/")
                        result = mUtil.divide(operand1, operand2);
                    else if(currentTokenStr == "^")
                        result = mUtil.power(operand1, operand2);
                    else if(currentTokenStr == "E")
                        result = mUtil.scientificNotation(operand1, operand2);
                    else if(currentTokenStr == "mod")
                        result = mUtil.mod(operand1, operand2);
                    else
                        throw CalculatorException("PostfixEvaluator: evaluate(): no binary operator: " + std::string(currentTokenStr));
                }
                catch(MathException& e)
                {
                    throw CalculatorException(e.what());
                }

                operandStack.push(result);
            }
        }
        else if(currentToken.tokenType == Token::FUNCTION)
        {
            arity = CalculatorUtil::getArity(currentTokenStr);

            if(arity < 0)
            {
                throw CalculatorException("PostfixEvaluator: evaluate(): function arity < 0");
            }
            if(arity == 1)
            {
                double operand = 0;

                if(!operandStack.empty())
                {
                    operand = operandStack.top();
                    operandStack.pop();
                }
                else
                    throw CalculatorException("Syntax Error: missing function argument(s)");

                try
                {
                    if(currentTokenStr == "sin" && angleMode == MathUtil::RADIANS)
                        result = mUtil.sineInRadians(operand);
                    else if(currentTokenStr == "cos" && angleMode == MathUtil::RADIANS)
                        result = mUtil.cosineInRadians(operand);
                    else if(currentTokenStr == "tan" && angleMode == MathUtil::RADIANS)
                        result = mUtil.tangentInRadians(operand);
                    else if(currentTokenStr == "sin" && angleMode == MathUtil::DEGREES)
                        result = mUtil.sineInDegrees(operand);
                    else if(currentTokenStr == "cos" && angleMode == MathUtil::DEGREES)
                        result = mUtil.cosineInDegrees(operand);
                    else if(currentTokenStr == "tan" && angleMode == MathUtil::DEGREES)
                        result = mUtil.tangentInDegrees(operand);
                    else if(currentTokenStr == "asin" && angleMode == MathUtil::DEGREES)
                        result = mUtil.asineInDegrees(operand);
                    else if(currentTokenStr == "acos" && angleMode == MathUtil::DEGREES)
                        result = mUtil.acosineInDegrees(operand);
                    else if(currentTokenStr == "atan" && angleMode == MathUtil::DEGREES)
                        result = mUtil.atangentInDegrees(operand);
                    else if(currentTokenStr == "asin" && angleMode == MathUtil::RADIANS)
                        result = mUtil.asineInRadians(operand);
                    else if(currentTokenStr == "acos" && angleMode == MathUtil::RADIANS)
                        result = mUtil.acosineInRadians(operand);
                    else if(currentTokenStr == "atan" && angleMode == MathUtil::RADIANS)
                        result = mUtil.atangentInRadians(operand);
                    else if(currentTokenStr == "log")
                        result = mUtil.log(operand);
                    else if(currentTokenStr == "ln")
                        result = mUtil.ln(operand);
                    else if(currentTokenStr == "sqrt")
                        result = mUtil.squareRoot(operand);
                    else if(currentTokenStr == "exp")
                        result = mUtil.exponent(operand);
                    else if(currentTokenStr == "abs")
                        result = mUtil.abs(operand);
                    else
                        throw CalculatorException("PostfixEvaluator: evaluate(): invalid function: " + std::string(currentTokenStr));
                }
                catch(MathException& e)
                {
                    throw CalculatorException(e.what());
                }
            }

            operandStack.push(result);
        }
    }

    if(operandStack.size() == 1)
    {
        result = operandStack.top();
    }
    else if(operandStack.size() < 1)
    {
        throw CalculatorException("Syntax Error 3: missing operand(s)");
    }
    else
    {
        throw CalculatorException("Syntax Error: missing operator(s)");
    }

    return result;
}

void PostfixEvaluator::assignment(std::string variable, double value)
{
    mBank.storeValueIntoVar(variable, value);
}

void PostfixEvaluator::setAngleMode(MathUtil::AngleMode mode)
{
    angleMode = mode;
}
