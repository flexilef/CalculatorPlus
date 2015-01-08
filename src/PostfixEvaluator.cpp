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

double PostfixEvaluator::evaluate(const std::string& postfix)
{
    std::stack<double> operandStack;
    std::stack<std::string> operatorStack;
    std::string currentTokenStr;

    tokenizer.setInput(postfix);

    while(tokenizer.hasNext())
    {
        Token currentToken = tokenizer.getNextToken();
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
                {
                    result = CalculatorUtil::unaryNegation(operand);
                    operandStack.push(result);
                }
            }
            else if(arity == 2)
            {
                double operand2 = operandStack.top();
                operandStack.pop();
                double operand1 = operandStack.top();
                operandStack.pop();
                double result = 0;

                if(currentTokenStr == "+")
                {
                    result = CalculatorUtil::add(operand1, operand2);
                    operandStack.push(result);
                }
                else if(currentTokenStr == "-")
                {
                    result = CalculatorUtil::subtract(operand1, operand2);
                    operandStack.push(result);
                }
            }
        }
    }

    result =operandStack.top();

    return result;
}
