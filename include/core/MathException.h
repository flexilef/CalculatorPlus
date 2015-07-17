#ifndef MATHEXCEPTION_H
#define MATHEXCEPTION_H

#include <stdexcept>
#include <string>

class MathException : public std::runtime_error
{
public:
    /** Default constructor */
    MathException(const std::string& Message = "")
        : std::runtime_error(Message.c_str())
    {
    }
protected:
private:
};

#endif // MATHEXCEPTION_H
