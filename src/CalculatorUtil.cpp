#include "../include/CalculatorUtil.h"
#include <cmath>

bool CalculatorUtil::isNumber(const std::string &str)
{
    if(isdigit(str[0]) || str == ".")
        return true;

    return false;
}

bool CalculatorUtil::isOperator(const std::string &str)
{
    const int LENGTH = 20;
    std::string operators[LENGTH] = {"(", ")", "+", "-", "*", "/", "^", "~", "E", "!", "=", "mod"};

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
    if(op == "+" || op == "-" || op == "*" || op == "/" || op == "^" || op == "E" || op == "=" || op == "mod")
        return 2;
    else if(op == "~" || op == "!")
        return 1;

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

///Math functions

double CalculatorUtil::unaryNegation(double operand)
{
    return -1*operand;
}

long long CalculatorUtil::factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

double CalculatorUtil::add(double left, double right)
{
    return left + right;
}

double CalculatorUtil::subtract(double left, double right)
{
    return left - right;
}

double CalculatorUtil::multiply(double left, double right)
{
    return left * right;
}

double CalculatorUtil::divide(double left, double right)
{
    return left / right;
}

double CalculatorUtil::power(double left, double right)
{
    return pow(left, right);
}

double CalculatorUtil::scientificNotation(double mantissa, double exponent)
{
    return mantissa*(pow(10, exponent));
}

double CalculatorUtil::mod(double left, double right)
{
    return fmod(left, right);
}

/*
double CalculatorUtil::squareRoot(short sign, double value)
{
    return sign*sqrt(value);
}

//Returns the result of a sin()
double CalculatorUtil::sine(short sign, double value)
{
    double radianResult = sign*sin(value);

    return radianResult;
}

//Returns the result of a cos()
double CalculatorUtil::cosine(short sign, double value)
{
    double radianResult = sign*cos(value);

    return radianResult;
}

//Returns the result of a cos()
double CalculatorUtil::tangent(short sign, double value)
{
    double radianResult = sign*tan(value);

    return radianResult;
}

double CalculatorUtil::atangent(short sign, double value)
{
    double result = sign*atan(value);

    return result;
}

double CalculatorUtil::acosine(short sign, double value)
{
    double result =  sign*acos(value);

    return result;
}

double CalculatorUtil::asine(short sign, double value)
{
    double result =  sign*asin(value);

    return result;
}

double CalculatorUtil::log(short sign, double value)
{
    return sign*log10(value);
}

double CalculatorUtil::ln(short sign, double value)
{
    return 0;
}

double CalculatorUtil::exponent(short sign, double value)
{
    return sign*exp(value);
}

double CalculatorUtil::UnaryNegation(double value)
{
    return value * -1;
}

double CalculatorUtil::percent(double value)
{
    return value * .01;
}

//Max is 20! possible to modify input if ! found to include ie.
//3! = 3*2*1
long long CalculatorUtil::factorial(int value)
{
    unsigned long long answer = 1;

    if(value < 0)
    {
        return -1;
    }

    for(int i=1; i<=value; i++)
    {
        answer *= i;
    }

    return answer;
}
*/
