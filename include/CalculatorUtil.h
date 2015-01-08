
namespace CalculatorUtil
{
    bool isNumber(const std::string&);
    bool isOperator(const std::string&);
    bool isFunction(const std::string&);
    int getArity(const std::string&);
    int getPrecedence(const std::string&);

    //math functions

    double unaryNegation(double);
    double add(double, double);
    double subtract(double, double);
    double multiply(double, double);
    double divide(double, double);
    double power(double, double);
    double scientificNotation(double, double);
    double mod(double, double);
    long long factorial(int);

    /*double sine(short,double);
    double cosine(short,double);
    double tangent(short,double);
    double asine(short,double);
    double acosine(short,double);
    double atangent(short,double);
    double log(short,double);
    double ln(short,double);
    double exponent(short,double);
    double squareRoot(short, double);
    double percent(double);
    void assignment(double, int);
    */
}
