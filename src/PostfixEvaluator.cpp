#include "../include/PostfixEvaluator.h"
#include "../include/CalculatorUtil.h"

#include <cstdlib>
#include <stack>

PostfixEvaluator::PostfixEvaluator()
{
    result = 0;
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
            int arity = CalculatorUtil::getArity(currentTokenStr);

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

                operandStack.push(result);
            }
            else if(arity == 2)
            {
                //operand2 needs to be popped before operand1 for order to be right
                double operand2 = operandStack.top();
                operandStack.pop();
                double operand1 = operandStack.top();
                operandStack.pop();
                double result = 0;

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

                operandStack.push(result);
            }
        }
    }

    result = operandStack.top();

    return result;
}
