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

std::string InfixToPostfixConverter::convertToPostfix(const std::string infix)
{
    input = infix;
    convert();

    return output;
}

void InfixToPostfixConverter::convert()
{
    std::string postfix = "";
    std::stack<std::string> operatorStack;

    std::string topOperator;
    std::string functionStr;
    std::string variableStr;

    int inputLength = input.length();
    bool isNegative = false;

    for(int i = 0; i < inputLength; i++)
    {
        bool done = false;

        std::string nextCharacter = input.substr(i, 1);

        std::string lastCharacter;

        //lastCharacter can't be a whitespace or the first character
        if(i > 0 && input.substr(i-1, 1) != " ")
        {
            lastCharacter = input.substr(i-1, 1);
        }

        if(nextCharacter != " ")
        {
            if(isNumber(nextCharacter))
            {
                postfix+=nextCharacter;
            }
            //is part of a function or variable name
            else if(isalpha(input[i]))
            {
                functionStr+=nextCharacter;
                variableStr+=nextCharacter;

                if(isFunction(functionStr))
                {
                    operatorStack.push(functionStr);

                    //reset them
                    functionStr = "";
                    variableStr = "";
                }
            }
            //operator found
            else
            {
                //add a white space between each operand and each operator
                postfix+=" ";

                //handle variable names found before we handle operators
                if(!variableStr.empty())
                {
                    //variable is ready to be added. (we are assuming that variableStr is a valid var here)
                    //when we evaluate, we'll know for sure if it's a syntax error or not
                    postfix+=variableStr;
                    postfix+=" ";

                    //reset them
                    variableStr = "";
                    functionStr = "";
                }

                //handle operators
                if(nextCharacter == "^")
                    operatorStack.push(nextCharacter);
                else if(isOperator(nextCharacter))
                {
                    //unary negation check
                    if(nextCharacter == "-")
                    {
                        if(i == 0)
                            isNegative = true;
                        else if(isOperator(lastCharacter))
                            isNegative = true;
                        else if(lastCharacter == "(")
                            isNegative = true;

                        //internal representation of unary negation: ~
                        if(isNegative)
                        {
                            nextCharacter = "~";
                            isNegative = false;
                        }
                    }

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
                }
                else if(nextCharacter == "(")
                {
                    operatorStack.push(nextCharacter);
                }
                else if(nextCharacter == ")")
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
            }
        }// end if
    }//end for

    //unload the rest of the operators
    while(!operatorStack.empty())
    {
        topOperator = operatorStack.top();
        operatorStack.pop();

        postfix+=" ";
        postfix+=topOperator;
    }

    output = postfix;
}

int InfixToPostfixConverter::getPrecedence(std::string op)
{
    if(op == "(" || op == ")")
        return 0;
    else if(op == "+" || op == "-")
        return 1;
    else if(op == "*" || op == "/")
        return 2;
    else if(op == "^")
        return 3;
    else if(op == "~")
        return 4;
    else if(op == "sin" || op == "cos" || op == "tan" || op == "ln")
        return 5;

    return -1;
}

/**
*Task: Checks whether a character is considered a valid operand.
*@param character  the char we are checking
*@return true  if character is a number, letter, or a period, otherwise false
*/
bool InfixToPostfixConverter::isNumber(const std::string character)
{
    if(isdigit(character[0]) || character == ".")
        return true;

    return false;
}

bool InfixToPostfixConverter::isOperator(const std::string str)
{
    std::string operators[10] = {"+", "-", "~", "*", "/", "^", "sin", "cos", "tan"};

    if(str.empty())
        return false;
    else
    {
        for(int i = 0; i < 10; i++)
        {
            if(str == operators[i])
                return true;
        }
    }

    return false;
}

bool InfixToPostfixConverter::isFunction(const std::string str)
{
    std::string functions[10] = {"sin", "cos", "tan", "ln"};

    for(int i = 0; i < 10; i++)
    {
        if(functions[i] == str)
            return true;
    }

    return false;
}
