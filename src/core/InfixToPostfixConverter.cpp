//#include <cctype>
#include <stack>
#include <cstdlib>
#include <iostream>

#include "../../include/core/InfixToPostfixConverter.h"
#include "../../include/core/CalculatorUtil.h"

#include "../../include/core/MathTokenizer.h"
#include "../../include/core/CalculatorException.h"

InfixToPostfixConverter::InfixToPostfixConverter()
{
    input = "";
    output = "";
}

InfixToPostfixConverter::~InfixToPostfixConverter()
{
    //dtor
}

std::string InfixToPostfixConverter::convertToPostfix(const std::string &infix)
{
    input = infix;
    convert();

    return output;
}

void InfixToPostfixConverter::convert()
{
    MathTokenizer tokenizer;
    std::stack<std::string> operatorStack;
    std::string postfix;
    std::string topOperator;
    std::string currentTokenStr;
    std::string lastTokenStr;
    Token currentToken;
    int tokenIndex = 0;

    tokenizer.setInput(input);

    while(tokenizer.hasNext())
    {
        bool done = false;
        currentToken = tokenizer.getNextToken();
        currentTokenStr = currentToken.getString();

        if(currentToken.tokenType == Token::NUMBER)
        {
            postfix+=currentTokenStr;
            postfix+=" ";
            lastTokenStr = currentTokenStr;
        }
        else if(currentToken.tokenType == Token::FUNCTION)
        {
            operatorStack.push(currentTokenStr);
            lastTokenStr = currentTokenStr;
        }
        else if(currentToken.tokenType == Token::VARIABLE)
        {
            postfix+=currentTokenStr;
            postfix+=" ";
            lastTokenStr = currentTokenStr;
        }
        else if(currentToken.tokenType == Token::OPERATOR)
        {
            if(currentTokenStr == "(")
            {
                operatorStack.push(currentTokenStr);
            }
            else if(currentTokenStr == ")")
            {
                topOperator = operatorStack.top();
                operatorStack.pop();

                while(topOperator != "(")
                {
                    postfix+=topOperator;
                    postfix+=" ";
                    topOperator = operatorStack.top();
                    operatorStack.pop();
                }
            }
            else
            {
                if(currentTokenStr == "-")
                {
                    if(tokenIndex == 0)
                        currentTokenStr = "~";
                    else if(CalculatorUtil::isOperator(lastTokenStr) && lastTokenStr != ")")
                        currentTokenStr = "~";
                    else if(lastTokenStr == "(")
                        currentTokenStr = "~";
                }

                while(!done && !operatorStack.empty())
                {
                    topOperator = operatorStack.top();

                    if(CalculatorUtil::getPrecedence(currentTokenStr) <= CalculatorUtil::getPrecedence(topOperator)
                            && currentTokenStr != "~" /*&& currentTokenStr != "^"*/) //this condition handles right associativity of ~ and ^.
                        //ie. --2 -> 2 ~ ~ and 1^2^3 -> 1 2 3 ^ ^ ^. But it's a bit confusing.
                    {
                        postfix+=topOperator;
                        postfix+=" ";
                        operatorStack.pop();
                    }
                    else
                        done = true;
                }//end while
                operatorStack.push(currentTokenStr);
            }//end else
            lastTokenStr = currentTokenStr;
        }//end else if
        tokenIndex++;
    }//end while

    //takes care of remaining operators
    while(!operatorStack.empty())
    {
        topOperator = operatorStack.top();
        operatorStack.pop();

        postfix+=" ";
        postfix+=topOperator;
    }

    output = postfix;
}
