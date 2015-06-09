#ifndef DIVIDEBYZEROEXCEPTION_H
#define DIVIDEBYZEROEXCEPTION_H

#include <stdexcept>
#include <string>

class DivideByZeroException : public std::domain_error
{
public:
    /** Default constructor */
    DivideByZeroException(const std::string& Message = "")
        : domain_error(Message.c_str())
    {
    }
private:
};

#endif // DIVIDEBYZEROEXCEPTION_H
