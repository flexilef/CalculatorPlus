#ifndef SYNTAXEXCEPTION_H
#define SYNTAXEXCEPTION_H

#include <stdexcept>
#include <string>

#include "../include/MathException.h"

class SyntaxException : public MathException
{
    public:
        /** Default constructor */
        SyntaxException(const std::string& Message = "")
        : MathException(Message)
        {}
    protected:
    private:
};

#endif // SYNTAXEXCEPTION_H
