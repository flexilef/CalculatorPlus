#include "../include/PostfixEvaluator.h"
#include "../include/CalculatorUtil.h"

#include <cstdlib>
#include <stack>

PostfixEvaluator::PostfixEvaluator()
{
    answer = 0;
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
    std::string currentTokenStr;
    Token currentToken;
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
        else if(currentToken.tokenType == Token::OPERATOR)
        {
            arity = CalculatorUtil::getArity(currentTokenStr);

            if(arity < 0)
            {
                std::cout << "Error....\n";
            }
            else if(arity == 1)
            {
                double operand = operandStack.top();
                operandStack.pop();

                if(currentTokenStr == "~")
                    result = CalculatorUtil::unaryNegation(operand);
                else if(currentTokenStr == "!")
                    result = CalculatorUtil::factorial(operand);
                else if(currentTokenStr == "%")
                    result = CalculatorUtil::percent(operand);
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
                    result = CalculatorUtil::add(operand1, operand2);
                else if(currentTokenStr == "-")
                    result = CalculatorUtil::subtract(operand1, operand2);
                else if(currentTokenStr == "*")
                    result = CalculatorUtil::multiply(operand1, operand2);
                else if(currentTokenStr == "/")
                    result = CalculatorUtil::divide(operand1, operand2);
                else if(currentTokenStr == "^")
                    result = CalculatorUtil::power(operand1, operand2);
                else if(currentTokenStr == "E")
                    result = CalculatorUtil::scientificNotation(operand1, operand2);
                else if(currentTokenStr == "mod")
                    result = CalculatorUtil::mod(operand1, operand2);
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
                std::cout << "Error....\n";
            }
            if(arity == 1)
            {
                double operand = operandStack.top();
                operandStack.pop();

                if(currentTokenStr == "sin")
                    result = CalculatorUtil::sine(operand);
                else if(currentTokenStr == "cos")
                    result = CalculatorUtil::cosine(operand);
                else if(currentTokenStr == "tan")
                    result = CalculatorUtil::tangent(operand);
                else if(currentTokenStr == "asin")
                    result = CalculatorUtil::asine(operand);
                else if(currentTokenStr == "acos")
                    result = CalculatorUtil::acosine(operand);
                else if(currentTokenStr == "atan")
                    result = CalculatorUtil::atangent(operand);
                else if(currentTokenStr == "log")
                    result = CalculatorUtil::log(operand);
                else if(currentTokenStr == "ln")
                    result = CalculatorUtil::ln(operand);
                else if(currentTokenStr == "sqrt")
                    result = CalculatorUtil::squareRoot(operand);
                else if(currentTokenStr == "exp")
                    result = CalculatorUtil::exponent(operand);
                else if(currentTokenStr == "abs")
                    result = CalculatorUtil::abs(operand);
                else
                    std::cout << "Error: no function: " << currentTokenStr << " : found.\n\n";
            }

            operandStack.push(result);
        }
    }

    result = operandStack.top();

    return result;
}
