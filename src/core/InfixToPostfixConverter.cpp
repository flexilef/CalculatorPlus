/*
This file is part of Calculator+
Copyright (C) 2015 Felix Lee

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

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
    MathTokenizer tokenizer(input);
    std::stack<std::string> operatorStack;
    std::string postfix;
    std::string topOperator;
    std::string currentTokenStr;
    std::string lastTokenStr;
    Token currentToken;
    int tokenIndex = 0;

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
                if(!operatorStack.empty())
                {
                    topOperator = operatorStack.top();
                    operatorStack.pop();
                }

                while(topOperator != "(")
                {
                    postfix+=topOperator;
                    postfix+=" ";

                    if(!operatorStack.empty())
                    {
                        topOperator = operatorStack.top();
                        operatorStack.pop();
                    }
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

                    if(CalculatorUtil::getPrecedence(currentTokenStr) <= CalculatorUtil::getPrecedence(topOperator))
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
