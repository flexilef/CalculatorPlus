#ifndef SYNTAXEXCEPTION_H
#define SYNTAXEXCEPTION_H

#include <stdexcept>
#include <string>

class SyntaxException : public std::runtime_error
{
    public:
        /** Default constructor */
        SyntaxException(const std::string& Message = "")
        : runtime_error(Message.c_str())
        {}
    protected:
    private:
};

#endif // SYNTAXEXCEPTION_H
