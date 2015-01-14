#include "../include/PostfixEvaluator.h"
#include "../include/CalculatorUtil.h"
#include "../include/MathUtil.h"

#include <cstdlib>
#include <iostream>
#include <stack>

PostfixEvaluator::PostfixEvaluator(MemoryBank& mb) : theBank(mb)
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
    std::stack<double> operandStack;
    Token currentToken;
    std::string currentTokenStr;
    int arity = -1;
    double result = 0;

    tokenizer.setInput(postfix);

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
            double variableValue = theBank.getValueFromVar(currentTokenStr);
            operandStack.push(variableValue);
        }
        else if(currentToken.tokenType == Token::OPERATOR)
        {
            arity = CalculatorUtil::getArity(currentTokenStr);

            if(arity < 0)
            {
                std::cout << "Error: operator arity < 0\n";
            }
            else if(arity == 1)
            {
                double operand = operandStack.top();
                operandStack.pop();

                if(currentTokenStr == "~")
                    result = MathUtil::unaryNegation(operand);
                else if(currentTokenStr == "!")
                    result = MathUtil::factorial(operand);
                else if(currentTokenStr == "%")
                    result = MathUtil::percent(operand);
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
                    result = MathUtil::add(operand1, operand2);
                else if(currentTokenStr == "-")
                    result = MathUtil::subtract(operand1, operand2);
                else if(currentTokenStr == "*")
                    result = MathUtil::multiply(operand1, operand2);
                else if(currentTokenStr == "/")
                    result = MathUtil::divide(operand1, operand2);
                else if(currentTokenStr == "^")
                    result = MathUtil::power(operand1, operand2);
                else if(currentTokenStr == "E")
                    result = MathUtil::scientificNotation(operand1, operand2);
                else if(currentTokenStr == "mod")
                    result = MathUtil::mod(operand1, operand2);
                //missing assignment operator
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
                    result = MathUtil::sine(operand);
                else if(currentTokenStr == "cos")
                    result = MathUtil::cosine(operand);
                else if(currentTokenStr == "tan")
                    result = MathUtil::tangent(operand);
                else if(currentTokenStr == "asin")
                    result = MathUtil::asine(operand);
                else if(currentTokenStr == "acos")
                    result = MathUtil::acosine(operand);
                else if(currentTokenStr == "atan")
                    result = MathUtil::atangent(operand);
                else if(currentTokenStr == "log")
                    result = MathUtil::log(operand);
                else if(currentTokenStr == "ln")
                    result = MathUtil::ln(operand);
                else if(currentTokenStr == "sqrt")
                    result = MathUtil::squareRoot(operand);
                else if(currentTokenStr == "exp")
                    result = MathUtil::exponent(operand);
                else if(currentTokenStr == "abs")
                    result = MathUtil::abs(operand);
                else
                    std::cout << "Error: no function: " << currentTokenStr << " : found.\n\n";
            }

            operandStack.push(result);
        }
    }

    result = operandStack.top();

    return result;
}
