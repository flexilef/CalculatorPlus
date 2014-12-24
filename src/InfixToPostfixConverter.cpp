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

double InfixToPostfixConverter::evaluate(const std::string &postfix)
{
    std::stack<double> valueStack;

    double result = 0;

    int inputLength = postfix.length();

    std::string numberStr;

    for(int i = 0; i < inputLength; i++)
    {
        if(isNumber(postfix.substr(i, 1)))
        {
            numberStr+=postfix[i];
        }

        else if(postfix.substr(i, 1) == " " && !numberStr.empty())
        {
            //operand is ready to be pushed
            double value = atof(numberStr.c_str());
            valueStack.push(value);

            //result number
            numberStr = "";
        }

        else if(isOperator(postfix.substr(i, 1)))
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

std::string InfixToPostfixConverter::convertToPostfix(const std::string &infix)
{
    input = infix;
    convert();

    return output;
}

void InfixToPostfixConverter::convert()
{
    std::stack<std::string> operatorStack;
    std::string postfix;
    std::string topOperator;
    std::string lastToken;
    int tokenIndex = 0;

    tokenizer.setInput(input);

    while(tokenizer.hasNext())
    {
        bool done = false;
        Token currentToken = tokenizer.getNextToken();

        if(currentToken.tokenType == Token::NUMBER)
        {
            postfix+=currentToken.getString();
            postfix+=" ";
            lastToken = currentToken.getString();
        }
        else if(currentToken.tokenType == Token::FUNCTION)
        {
            operatorStack.push(currentToken.getString());
            lastToken = currentToken.getString();

        }
        else if(currentToken.tokenType == Token::VARIABLE)
        {
            postfix+=currentToken.getString();
            postfix+=" ";
            lastToken = currentToken.getString();

        }
        else if(currentToken.tokenType == Token::OPERATOR)
        {
            if(currentToken.getString() == "^")
            {
                operatorStack.push(currentToken.getString());
                lastToken = currentToken.getString();
            }
            else if(currentToken.getString() == "(")
            {
                operatorStack.push(currentToken.getString());
            }
            else if(currentToken.getString() == ")")
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
                while(!done && !operatorStack.empty())
                {
                    topOperator = operatorStack.top();

                    if(getPrecedence(currentToken.getString()) <= getPrecedence(topOperator))
                    {
                        postfix+=topOperator;
                        postfix+=" ";
                        operatorStack.pop();
                    }
                    else
                        done = true;
                }

                operatorStack.push(currentToken.getString());
            }
        }
    }

    //takes care of remaindered operators
    while(!operatorStack.empty())
    {
        topOperator = operatorStack.top();
        operatorStack.pop();

        postfix+=" ";
        postfix+=topOperator;
    }

    output = postfix;
}

int InfixToPostfixConverter::getPrecedence(const std::string &op)
{
    if(op == "(" || op == ")")
        return 0;
    else if(op == "+" || op == "-")
        return 10;
    else if(op == "*" || op == "/")
        return 20;
    else if(op == "^")
        return 30;
    else if(op == "~")
        return 40;
    else if(isFunction(op))
        return 50;

    return -1;
}

/**
*Task: Checks whether a character is considered a valid operand.
*@param character  the char we are checking
*@return true  if character is a number, letter, or a period, otherwise false
*/
bool InfixToPostfixConverter::isNumber(const std::string &str)
{
    if(isdigit(str[0]) || str == ".")
        return true;

    return false;
}

bool InfixToPostfixConverter::isOperator(const std::string &str)
{
    std::string operators[10] = {"+", "-", "~", "*", "/", "^"};

    if(!str.empty())
    {
        for(int i = 0; i < 10; i++)
        {
            if(str == operators[i])
                return true;
        }
    }

    return false;
}

bool InfixToPostfixConverter::isFunction(const std::string &str)
{
    std::string functions[10] = {"sin", "cos", "tan", "ln"};

    if(!str.empty())
    {
        for(int i = 0; i < 10; i++)
        {
            if(functions[i] == str)
                return true;
        }
    }

    return false;
}
