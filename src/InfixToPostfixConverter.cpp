#include "../include/InfixToPostfixConverter.h"

#include <cctype>
#include <stack>
#include <stdlib.h>

InfixToPostfixConverter::InfixToPostfixConverter()
{
    input = "";
    output = "";
}

InfixToPostfixConverter::~InfixToPostfixConverter()
{
    //dtor
}

double InfixToPostfixConverter::evaluate(const std::string postfix)
{
    std::stack<double> valueStack;

    double result = 0;

    int inputLength = postfix.length();

    std::string numberStr;

    for(int i = 0; i < inputLength; i++)
    {
        if(isOperand(postfix[i]))
        {
            numberStr+=postfix[i];
        }

        else if(postfix[i] == ' ' && !numberStr.empty())
        {
            //operand is ready to be pushed
            double value = atof(numberStr.c_str());
            valueStack.push(value);

            //result number
            numberStr = "";
        }

        else if(isOperator(postfix[i]))
        {
            double operandTwo = valueStack.top();
            valueStack.pop();

            double operandOne = valueStack.top();
            valueStack.pop();

            result = operandOne*operandTwo;
            valueStack.push(result);
        }
    }

    return result;
}

std::string InfixToPostfixConverter::convertToPostfix(const std::string infix)
{
    input = infix;
    convert();

    return output;
}

void InfixToPostfixConverter::convert()
{
    std::string postfix = "";
    std::stack<char> operatorStack;

    int inputLength = input.length();
    char topOperator;

    for(int i = 0; i < inputLength; i++)
    {
        bool done = false;
        char nextCharacter = input[i];

        if(isOperand(nextCharacter))
        {
            postfix+=nextCharacter;
        }
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
            case '/':
            {
                while(!done && !operatorStack.empty())
                {
                    topOperator = operatorStack.top();
                    if(getPrecedence(nextCharacter) <= getPrecedence(topOperator))
                    {
                        postfix+=topOperator;
                        postfix+=" ";
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
                    postfix+=" ";
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
        postfix+=" ";
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

/**
*Task: Checks whether a character is considered a valid operand.
*@param character  the char we are checking
*@return true  if character is a number, letter, or a period, otherwise false
*/
bool InfixToPostfixConverter::isOperand(char character)
{
    if(isalnum(character) || character == '.')
        return true;

    return false;
}

bool InfixToPostfixConverter::isOperator(char character)
{
    char operators[10] = {'+', '-', '*', '/', '^'};

    for(int i = 0; i < 10; i++)
    {
        if(character == operators[i])
            return true;
    }

    return false;
}
