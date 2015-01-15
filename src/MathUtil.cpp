#include "../include/MathUtil.h"
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
    return left / right;
}

double MathUtil::power(double left, double right)
{
    return pow(left, right);
}

double MathUtil::scientificNotation(double mantissa, double exponent)
{
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
    return log10(value);
}

double MathUtil::ln(double value)
{
    return std::log(value);
}

double MathUtil::squareRoot(double value)
{
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
