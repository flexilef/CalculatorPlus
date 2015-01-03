#include "../include/CalculatorUtil.h"

bool CalculatorUtil::isNumber(const std::string &str)
{
    if(isdigit(str[0]) || str == ".")
        return true;

    return false;
}

bool CalculatorUtil::isOperator(const std::string &str)
{
    const int LENGTH = 20;
    std::string operators[LENGTH] = {"(", ")", "+", "-", "*", "/", "^", "~", "E", "!", "="};

    if(!str.empty())
    {
        for(int i = 0; i < LENGTH; i++)
        {
            if(str == operators[i])
                return true;
        }
    }

    return false;
}

bool CalculatorUtil::isFunction(const std::string &str)
{
    const int LENGTH = 20;
    std::string functions[LENGTH] = {"abs", "acos", "asin", "atan", "cbrt", "cos", "exp", "ln", "log", "sin", "sqrt", "tan"};

    if(!str.empty())
    {
        for(int i = 0; i < LENGTH; i++)
        {
            if(functions[i] == str)
                return true;
        }
    }

    return false;
}

int CalculatorUtil::getPrecedence(const std::string &op)
{
    if(op == "(" || op == ")")
        return 0;
    else if(op == "=")
        return 5;
    else if(op == "+" || op == "-")
        return 10;
    else if(op == "*" || op == "/")
        return 20;
    else if(op == "^")
        return 60;
    else if(op == "~" || op == "E" || op == "!")
        return 40;
    else if(CalculatorUtil::isFunction(op))
        return 50;

    return -1;
}
