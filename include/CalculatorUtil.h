
namespace CalculatorUtil
{
    //helper
    bool isNumber(const std::string&);
    bool isOperator(const std::string&);
    bool isFunction(const std::string&);
    int getArity(const std::string&);
    int getPrecedence(const std::string&);
    bool almostEqual(double, double, int);

    //math functions

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
    void assignment(double, int);

    //trig functions
    double sine(double);
    double cosine(double);
    double tangent(double);
    double asine(double);
    double acosine(double);
    double atangent(double);

    //basic functions
    double log(double);
    double ln(double);
    double exponent(double);
    double squareRoot(double);
    double abs(double);
}
