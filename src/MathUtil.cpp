#include "../include/MathUtil.h"
#include "../include/DivideByZeroException.h"
#include "../include/DomainException.h"
#include "../include/SyntaxException.h"
#include <cmath>

MathUtil::MathUtil()
{
}

MathUtil::~MathUtil()
{

}

//unary operators
double MathUtil::unaryNegation(double operand)
{
    return -1*operand;
}

long long MathUtil::factorial(int n)
{
    if(n<0)
    {
        throw DomainException("Domain Error: negative operand");
    }
    else if(n>20)
        throw DomainException("Domain Error: operand > 20");

    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

double MathUtil::percent(double value)
{
    return value * .01;
}

//binary operators
double MathUtil::add(double left, double right)
{
    return left + right;
}

double MathUtil::subtract(double left, double right)
{
    return left - right;
}

double MathUtil::multiply(double left, double right)
{
    return left * right;
}

double MathUtil::divide(double left, double right)
{
    if(right == 0)
        throw DivideByZeroException("Divide By 0 Error");
    return left / right;
}

double MathUtil::power(double left, double right)
{
    if(left == 0 && right == 0)
    {
        throw DomainException("Domain Error: x and y are 0");
    }
    //if right is not integer and left is negative
    else if((right - floor(right) != 0) && left <0)
    {
        throw DomainException("Domain Error: non-integer and negative operands");
    }

    return pow(left, right);
}

double MathUtil::scientificNotation(double mantissa, double exponent)
{
    if(exponent - floor(exponent) != 0)
        throw SyntaxException("Syntax Error: invalid exponent");
    return mantissa*(pow(10, exponent));
}

double MathUtil::mod(double left, double right)
{
    return fmod(left, right);
}

//trig functions
double MathUtil::sine(double radianValue)
{
    double radianResult = sin(radianValue);

    return radianResult;
}

double MathUtil::cosine(double radianValue)
{
    double radianResult = cos(radianValue);

    return radianResult;
}

double MathUtil::tangent(double radianValue)
{
    double radianResult = tan(radianValue);

    return radianResult;
}

double MathUtil::asine(double radianValue)
{
    double radianResult =  asin(radianValue);

    return radianResult;
}

double MathUtil::acosine(double radianValue)
{
    double radianResult =  acos(radianValue);

    return radianResult;
}

double MathUtil::atangent(double radianValue)
{
    double radianResult =  atan(radianValue);

    return radianResult;
}

//basic functions
double MathUtil::log(double value)
{
    if(value <= 0)
        throw DomainException("Domain Error: argument is 0 or negative");

    return log10(value);
}

double MathUtil::ln(double value)
{
    if(value <= 0)
        throw DomainException("Domain Error: argument is 0 or negative");
    return std::log(value);
}

double MathUtil::squareRoot(double value)
{
    if(value < 0)
        throw DomainException("Domain Error: argument is negative");
    return sqrt(value);
}

double MathUtil::exponent(double value)
{
    return exp(value);
}

double MathUtil::abs(double value)
{
    return std::abs(value);
}
