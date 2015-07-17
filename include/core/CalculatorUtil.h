#ifndef CALCULATORUTIL_H
#define CALCULATORUTIL_H

#include <iostream>

namespace CalculatorUtil
{
    //helper
    bool isNumber(const std::string&);
    bool isOperator(const std::string&);
    bool isFunction(const std::string&);
    int getArity(const std::string&);
    int getPrecedence(const std::string&);
    bool almostEqual(double, double, int);
    bool isInfix(const std::string&);
}

#endif // CALCULATORUTIL_H
