#include "../include/CalculatorUtil.h"
#include <cmath>
#include <limits>

bool CalculatorUtil::isNumber(const std::string &str)
{
    if(isdigit(str[0]) || str == ".")
        return true;

    return false;
}

bool CalculatorUtil::isOperator(const std::string &str)
{
    const int LENGTH = 20;
    std::string operators[LENGTH] = {"(", ")", "+", "-", "*", "/", "^", "~", "E", "!", "%", "mod", "="};

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

int CalculatorUtil::getArity(const std::string &op)
{
    if(op == "+" || op == "-" || op == "*" || op == "/" || op == "^" || op == "E" || op == "mod")
        return 2;
    else if(op == "~" || op == "!" || op == "%" || isFunction(op))   //note that the arity of a function is at least 1
        return 1;
    else if(op == "=")//special operators
        return 0;

    return -1;
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

//TODO: write a better one
bool CalculatorUtil::almostEqual(double a, double b, int ulp)
{
    //return std::abs(a - b) < std::numeric_limits<double>::epsilon()*std::abs(a + b)*ulp ||
    //       std::abs(a - b) < std::numeric_limits<double>::min();
    return (std::abs(a-b)/b) < .005 || std::abs(a-b) < .000001;
}
