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
    if(op == "+" || op == "-" || op == "*" || op == "/" || op == "^" || op == "E" || op == "=" || op == "mod")
        return 2;
    else if(op == "~" || op == "!" || op == "%" || isFunction(op))   //note that the arity of a function is at least 1
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

bool CalculatorUtil::almostEqual(double a, double b, int ulp)
{
    return std::abs(a - b) < std::numeric_limits<double>::epsilon()*std::abs(a + b)*ulp ||
           std::abs(a - b) < std::numeric_limits<double>::min();
}

///Math functions

//unary operators
double CalculatorUtil::unaryNegation(double operand)
{
    return -1*operand;
}

long long CalculatorUtil::factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

double CalculatorUtil::percent(double value)
{
    return value * .01;
}

//binary operators
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

//trig functions
double CalculatorUtil::sine(double radianValue)
{
    double radianResult = sin(radianValue);

    return radianResult;
}

double CalculatorUtil::cosine(double radianValue)
{
    double radianResult = cos(radianValue);

    return radianResult;
}

double CalculatorUtil::tangent(double radianValue)
{
    double radianResult = tan(radianValue);

    return radianResult;
}

double CalculatorUtil::asine(double radianValue)
{
    double radianResult =  asin(radianValue);

    return radianResult;
}

double CalculatorUtil::acosine(double radianValue)
{
    double radianResult =  acos(radianValue);

    return radianResult;
}

double CalculatorUtil::atangent(double radianValue)
{
    double radianResult =  atan(radianValue);

    return radianResult;
}

//basic functions
double CalculatorUtil::log(double value)
{
    return log10(value);
}

double CalculatorUtil::ln(double value)
{
    return std::log(value);
}

double CalculatorUtil::squareRoot(double value)
{
    return sqrt(value);
}

double CalculatorUtil::exponent(double value)
{
    return exp(value);
}

double CalculatorUtil::abs(double value)
{
    return std::abs(value);
}

/*
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
