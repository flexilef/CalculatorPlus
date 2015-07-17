#ifndef MATHUTIL_H
#define MATHUTIL_H

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

    static const double PI()
    {
        return 3.14159265358979323846;
    }

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
    double asineInRadians(double);
    double acosineInRadians(double);
    double atangentInRadians(double);
    double asineInDegrees(double);
    double acosineInDegrees(double);
    double atangentInDegrees(double);

    //basic functions
    double log(double);
    double ln(double);
    double exponent(double);
    double squareRoot(double);
    double abs(double);

    //helper functions
    double wrapDegrees0To360(double);
    double wrapRadians0To2PI(double);
    bool isInteger(double);
};

#endif // MATHUTIL_H
