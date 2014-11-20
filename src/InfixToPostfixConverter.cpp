#include "../include/InfixToPostfixConverter.h"

#include <cctype>
#include <stack>

InfixToPostfixConverter::InfixToPostfixConverter()
{
    input = "";
    output = "";
}

InfixToPostfixConverter::~InfixToPostfixConverter()
{
    //dtor
}

void InfixToPostfixConverter::convert()
{
    std::string postfix = "";
    std::stack<char> operatorStack;

    int characterCount = input.length();
    char topOperator;

    for(int i = 0; i < characterCount; i++)
    {
        bool done = false;
        char nextCharacter = input[i];

        if(isVariable(nextCharacter))
            postfix+=nextCharacter;
        else
        {
            //add a white space between operands and operators to handle
            //multiple digit numbers and decimals
            postfix+=" ";

            switch(nextCharacter)
            {
            case '^':
            {
                operatorStack.push(nextCharacter);
                break;
            }
            case '+':
            case'-':
            case '*':
            case '.':
            {
                while(!done && !operatorStack.empty())
                {
                    topOperator = operatorStack.top();
                    if(getPrecedence(nextCharacter) <= getPrecedence(topOperator))
                    {
                        postfix+=topOperator;
                        operatorStack.pop();
                    }
                    else
                        done = true;
                }
                operatorStack.push(nextCharacter);
                break;
            }

            case '(':
            {
                operatorStack.push(nextCharacter);
                break;
            }
            case ')':
            {
                topOperator = operatorStack.top();
                operatorStack.pop();

                while(topOperator != '(')
                {
                    postfix+=topOperator;
                    topOperator = operatorStack.top();
                    operatorStack.pop();
                }
                break;
            }

            default:
                break;
            }// end switch
        }// end if
    }//end for

    while(!operatorStack.empty())
    {
        topOperator = operatorStack.top();
        operatorStack.pop();

        postfix+=topOperator;
    }

    output = postfix;
}

int InfixToPostfixConverter::getPrecedence(char op)
{
    switch(op)
    {
    case '(':
        return 0;
    case ')':
        return 0;
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    }

    return -1;
}

bool InfixToPostfixConverter::isVariable(char character)
{
    if(isalnum(character) || character == '.')
        return true;

    return false;
}
