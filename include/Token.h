#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

class Token
{
    public:

        enum Type
        {
            NUMBER,
            VARIABLE,
            OPERATOR,
            FUNCTION,
        };

        Type tokenType;

        /** Default constructor */
        Token();

        Token(std::string, Type);

        /** Default destructor */
        virtual ~Token();

        std::string getString();

    protected:
    private:
        std::string tokenString;
};

#endif // TOKEN_H
