
namespace CalculatorUtil
{
//helper
bool isNumber(const std::string&);
bool isOperator(const std::string&);
bool isFunction(const std::string&);
int getArity(const std::string&);
int getPrecedence(const std::string&);
bool almostEqual(double, double, int);
void setError(std::string);
bool isInfix(const std::string&);
}
