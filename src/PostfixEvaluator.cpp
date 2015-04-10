#include "../include/PostfixEvaluator.h"
#include "../include/CalculatorUtil.h"
#include "../include/MathTokenizer.h"

#include <cstdlib>
#include <iostream>
#include <stack>

PostfixEvaluator::PostfixEvaluator(MemoryBank& mbref) : mBank(mbref)
{
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
    Token currentToken;
    std::string currentTokenStr;

    int arity = -1;
    double result = 0;

    std::string newVariable;
    std::string existingVariable;

    while(tokenizer.hasNext())
    {
        currentToken = tokenizer.getNextToken();
        currentTokenStr = currentToken.getString();

        if(currentToken.tokenType == Token::NUMBER)
        {
            double number = atof(currentTokenStr.c_str());
            operandStack.push(number);
        }
        else if(currentToken.tokenType == Token::VARIABLE)
        {
            if(mBank.hasVariable(currentTokenStr))
            {
                double variableValue = mBank.getValueFromVar(currentTokenStr);
                operandStack.push(variableValue);
                existingVariable = currentTokenStr;
            }
            else
                newVariable = currentTokenStr;
        }
        else if(currentToken.tokenType == Token::OPERATOR)
        {
            arity = CalculatorUtil::getArity(currentTokenStr);

            if(arity == 0)
            {
                if(currentTokenStr == "=")
                {
                    //case 1: new var and number. ie. a=1
                    if(newVariable != "" && existingVariable == "")
                    {
                        double operand = operandStack.top();
                        operandStack.pop();
                        result = operand;
                        assignment(newVariable, operand);
                        operandStack.push(result);
                    }
                    //case 2: existing var and new num. ie. a=1... a=2
                    else if(newVariable == "" && existingVariable != "")
                    {
                        double operand = operandStack.top();
                        operandStack.pop();
                        operandStack.pop();
                        result = operand;
                        assignment(existingVariable, operand);
                        operandStack.push(result);
                    }
                    //case 3: existing var and new var. ie. b=a where a=1 and b = new
                    else if(newVariable != "" && existingVariable != "")
                    {
                        double operand = operandStack.top();
                        operandStack.pop();
                        result = operand;
                        assignment(newVariable, operand);
                        operandStack.push(result);
                    }
                    //case 4: existing var and existing var. ie. a=b. *WIll NOT BE HANDLED*
                }
            }
            else if(arity == 1)
            {
                double operand = operandStack.top();
                operandStack.pop();

                if(currentTokenStr == "~")
                    result = mUtil.unaryNegation(operand);
                else if(currentTokenStr == "!")
                    result = mUtil.factorial(operand);
                else if(currentTokenStr == "%")
                    result = mUtil.percent(operand);
                else
                    std::cout << "Error: no unary operator: " << currentTokenStr << " found.\n\n";

                operandStack.push(result);
            }
            else if(arity == 2)
            {
                //operand2 needs to be popped before operand1 for order to be right
                double operand2 = operandStack.top();
                operandStack.pop();
                double operand1 = operandStack.top();
                operandStack.pop();

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
                    std::cout << "Error: no binary operator: " << currentTokenStr << " found.\n\n";

                operandStack.push(result);
            }
        }
        else if(currentToken.tokenType == Token::FUNCTION)
        {
            arity = CalculatorUtil::getArity(currentTokenStr);

            if(arity < 0)
            {
                std::cout << "Error: function arity < 0\n";
            }
            if(arity == 1)
            {
                double operand = operandStack.top();
                operandStack.pop();

                if(currentTokenStr == "sin")
                    result = mUtil.sine(operand);
                else if(currentTokenStr == "cos")
                    result = mUtil.cosine(operand);
                else if(currentTokenStr == "tan")
                    result = mUtil.tangent(operand);
                else if(currentTokenStr == "asin")
                    result = mUtil.asine(operand);
                else if(currentTokenStr == "acos")
                    result = mUtil.acosine(operand);
                else if(currentTokenStr == "atan")
                    result = mUtil.atangent(operand);
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
                    std::cout << "Error: no function: " << currentTokenStr << " : found.\n\n";
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
        result = 0;
        std::cout << "ERROR: empty stack : \n";
    }
    else
    {
        result = 0;
        std::cout << "ERROR: stack size: " << operandStack.size() << "\n";
    }

    return result;
}

void PostfixEvaluator::assignment(std::string variable, double value)
{
    mBank.storeValueIntoVar(variable, value);
}
