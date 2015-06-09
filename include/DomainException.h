#ifndef DOMAINEXCEPTION_H
#define DOMAINEXCEPTION_H

#include <stdexcept>
#include <string>

class DomainException : public std::domain_error
{
    public:
        /** Default constructor */
        DomainException(const std::string& Message = "")
        : domain_error(Message.c_str())
        {}
    protected:
    private:
};

#endif // DOMAINEXCEPTION_H
