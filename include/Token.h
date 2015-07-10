#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token
{
    public:
        enum Type
        {
            UNUSED = 0,
            NUMBER,
            VARIABLE,
            OPERATOR,
            FUNCTION,
            COMMAND,
        };

        Type tokenType;

        /** Default constructor */
        Token();
        Token(const std::string&, Type);
        /** Default destructor */
        virtual ~Token();

        std::string getString();

    protected:
    private:
        std::string tokenString;
};

#endif // TOKEN_H
