#include "../include/Token.h"

Token::Token()
{
    tokenString = "";
}

Token::Token(const std::string &str, Type type)
{
    tokenString = str;
    tokenType = type;
}

Token::~Token()
{
    //dtor
}

std::string Token::getString()
{
    return tokenString;
}
