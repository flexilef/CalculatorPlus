#ifndef DOMAINEXCEPTION_H
#define DOMAINEXCEPTION_H

#include <stdexcept>
#include <string>

#include "MathException.h"

class DomainException : public MathException
{
    public:
        /** Default constructor */
        DomainException(const std::string& Message = "")
        : MathException(Message)
        {}
    protected:
    private:
};

#endif // DOMAINEXCEPTION_H
