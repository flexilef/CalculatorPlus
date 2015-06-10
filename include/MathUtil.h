#ifndef MATHUTIL_H
#define MATHUTIL_H

#include <string>
#include "../include/MemoryBank.h"

class MathUtil
{
public:

    enum AngleMode
    {
        DEGREES = 0,
        RADIANS,
    };

    MathUtil();
    ~MathUtil();

    //unary operators
    double unaryNegation(double);
    long long factorial(int);
    double percent(double);

    //binary operators
    double add(double, double);
    double subtract(double, double);
    double multiply(double, double);
    double divide(double, double);
    double power(double, double);
    double scientificNotation(double, double);
    double mod(double, double);

    //trig functions
    double sineInRadians(double);
    double cosineInRadians(double);
    double tangentInRadians(double);
    double sineInDegrees(double);
    double cosineInDegrees(double);
    double tangentInDegrees(double);
    double asine(double);
    double acosine(double);
    double atangent(double);

    //basic functions
    double log(double);
    double ln(double);
    double exponent(double);
    double squareRoot(double);
    double abs(double);
};

#endif // MATHUTIL_H
