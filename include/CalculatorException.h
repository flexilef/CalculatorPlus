#ifndef CALCULATOREXCEPTION_H
#define CALCULATOREXCEPTION_H

#include <stdexcept>
#include <string>

class CalculatorException : public std::runtime_error
{
public:
    /** Default constructor */
    CalculatorException(const std::string& Message = "")
        : runtime_error(Message.c_str())
    {
    }
private:
};

#endif // CALCULATOREXCEPTION_H
