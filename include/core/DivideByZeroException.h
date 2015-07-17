#ifndef DIVIDEBYZEROEXCEPTION_H
#define DIVIDEBYZEROEXCEPTION_H

#include <stdexcept>
#include <string>

#include "MathException.h"

class DivideByZeroException : public MathException
{
public:
    /** Default constructor */
    DivideByZeroException(const std::string& Message = "")
        : MathException(Message)
    {
    }
private:
};

#endif // DIVIDEBYZEROEXCEPTION_H
