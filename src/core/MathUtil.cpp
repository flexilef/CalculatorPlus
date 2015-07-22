#include <cmath>

#include "../../include/core/MathUtil.h"

#include "../../include/core/DivideByZeroException.h"
#include "../../include/core/DomainException.h"
#include "../../include/core/SyntaxException.h"

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
        throw DomainException("Domain Error: !: negative operand");
    }
    else if(n>20)
        throw DomainException("Domain Error: !: operand > 20");

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
        throw DivideByZeroException("Divide By Zero Error");
    return left / right;
}

double MathUtil::power(double left, double right)
{
    if(left == 0 && right == 0)
        throw DomainException("Domain Error: ^: x and y are 0");
    else if(left < 0 && !isInteger(right))
        throw DomainException("Domain Error: ^: base < 0 and exponent is not an integer");

    return pow(left, right);
}

double MathUtil::scientificNotation(double mantissa, double exponent)
{
    if(!isInteger(exponent))
        throw SyntaxException("Syntax Error: E: exponent is not integer");
    return mantissa*(pow(10, exponent));
}

double MathUtil::mod(double left, double right)
{
    return fmod(left, right);
}

//trig functions
double MathUtil::sineInDegrees(double angle)
{
    double degreesResult = 0;
    double degrees = angle;

    if(degrees < 0 || degrees > 360)
        degrees = wrapDegrees0To360(degrees);

    if(degrees == 0)
        degreesResult = 0;
    else if(degrees == 90)
        degreesResult = 1;
    else if(degrees == 180)
        degreesResult = 0;
    else if(degrees == 270)
        degreesResult = -1;
    else if(degrees == 360)
        degreesResult = 0;
    else
        degreesResult = sin(degrees*MathUtil::PI()/180.0);

    return degreesResult;
}

double MathUtil::cosineInDegrees(double angle)
{
    double degreesResult = 0;
    double degrees = angle;

    if(degrees < 0 || degrees > 360)
        degrees = wrapDegrees0To360(degrees);

    if(degrees == 0)
        degreesResult = 1;
    else if(degrees == 90)
        degreesResult = 0;
    else if(degrees == 180)
        degreesResult = -1;
    else if(degrees == 270)
        degreesResult = 0;
    else if(degrees == 360)
        degreesResult = 1;
    else
        degreesResult = cos(degrees*MathUtil::PI()/180.0);

    return degreesResult;
}

double MathUtil::tangentInDegrees(double angle)
{
    double degreesResult = 0;
    double degrees = angle;

    if(degrees > 360 || degrees < 0)
        wrapDegrees0To360(angle);

    if(degrees == 0)
        degreesResult = 0;
    else if(degrees == 90)
        throw DomainException("Domain Error: tan(): argument = 90");
    else if(degrees == 180)
        degreesResult = 0;
    else if(degrees == 270)
        throw DomainException("Domain Error: tan(): argument = 270");
    else if(degrees == 360)
        degreesResult = 0;
    else
        degreesResult = tan(degrees*MathUtil::PI()/180.0);

    return degreesResult;
}

double MathUtil::sineInRadians(double angle)
{
    double radianResult = 0;
    double radians = angle;

    if(radians > 2*MathUtil::PI() || radians < 0)
        radians = wrapRadians0To2PI(angle);

    if(radians == 0)
        radianResult = 0;
    else if(radians == MathUtil::PI()/2)
        radianResult = 1;
    else if(radians == MathUtil::PI())
        radianResult = 0;
    else if(radians == 3*MathUtil::PI()/2)
        radianResult = -2;
    else if(radians == 2*MathUtil::PI())
        radianResult = 0;
    else
        radianResult = sin(radians);

    return radianResult;
}

double MathUtil::cosineInRadians(double angle)
{
    double radianResult = 0;
    double radians = angle;

    if(radians > 2*MathUtil::PI() || radians < 0)
        radians = wrapRadians0To2PI(angle);

    if(radians == 0)
        radianResult = 1;
    else if(radians == MathUtil::PI()/2)
        radianResult = 0;
    else if(radians == MathUtil::PI())
        radianResult = -1;
    else if(radians == 3*MathUtil::PI()/2)
        radianResult = 0;
    else if(radians == 2*MathUtil::PI())
        radianResult = 1;
    else
        radianResult = cos(radians);

    return radianResult;
}

double MathUtil::tangentInRadians(double angle)
{
    double radianResult = 0;
    double radians = angle;

    if(radians > 2*MathUtil::PI() || radians < 0)
        radians = wrapRadians0To2PI(angle);

    if(radians == 0)
        radianResult = 0;
    else if(radians == MathUtil::PI()/2)
        throw DomainException("Domain Error: tan(): argument = PI/2");
    else if(radians == MathUtil::PI())
        radianResult = 0;
    else if(radians == 3*MathUtil::PI()/2)
        throw DomainException("Domain Error: tan(): argument = 3PI/2");
    else if(radians == 2*MathUtil::PI())
        radianResult = 0;
    else
        radianResult = tan(radians);

    return radianResult;
}

double MathUtil::asineInRadians(double value)
{
    if(value < -1 || value > 1)
        throw(DomainException("Domain Error: asin(): argument > 1 or argument < -1"));

    return asin(value);
}

double MathUtil::acosineInRadians(double value)
{
    if(value < -1 || value > 1)
        throw(DomainException("Domain Error: acos(): argument > 1 or argument < -1"));

    return acos(value);
}

double MathUtil::atangentInRadians(double value)
{
    if(value < -1 || value > 1)
        throw(DomainException("Domain Error: atan(): argument > 1 or argument < -1"));

    return atan(value);
}

double MathUtil::asineInDegrees(double value)
{
    if(value < -1 || value > 1)
        throw(DomainException("Domain Error: asin(): argument > 1 or argument < -1"));

    return asin(value)*180.0/MathUtil::PI();
}

double MathUtil::acosineInDegrees(double value)
{
    if(value < -1 || value > 1)
        throw(DomainException("Domain Error: acos(): argument > 1 or argument < -1"));

    return acos(value)*180.0/MathUtil::PI();
}

double MathUtil::atangentInDegrees(double value)
{
    if(value < -1 || value > 1)
        throw(DomainException("Domain Error: atan(): argument > 1 or argument < -1"));

    return atan(value)*180.0/MathUtil::PI();
}

//basic functions
double MathUtil::log(double value)
{
    if(value <= 0)
        throw DomainException("Domain Error: log(): argument is 0 or negative");

    return log10(value);
}

double MathUtil::ln(double value)
{
    if(value <= 0)
        throw DomainException("Domain Error: ln(): argument is 0 or negative");
    return std::log(value);
}

double MathUtil::squareRoot(double value)
{
    if(value < 0)
        throw DomainException("Domain Error: sqrt(): argument is negative");
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

double MathUtil::wrapDegrees0To360(double degrees)
{
    double angle = fmod(degrees, 360);

    if(angle < 0)
        angle+=360;

    return angle;
}

double MathUtil::wrapRadians0To2PI(double radians)
{
    double twoPI = 2.0*MathUtil::PI();
    return radians - twoPI*floor(radians/twoPI);
}

bool MathUtil::isInteger(double value)
{
    if(value - floor(value) != 0)
        return false;

    return true;
}
