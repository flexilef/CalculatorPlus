#ifndef INFIXTOPOSTFIXCONVERTER_H
#define INFIXTOPOSTFIXCONVERTER_H

#include "InputConverter.h"

class InfixToPostfixConverter : public InputConverter
{
public:
    /** Default constructor */
    InfixToPostfixConverter();

    /** Default destructor */
    virtual ~InfixToPostfixConverter();

    std::string convertToPostfix(const std::string);

    double evaluate(const std::string);

private:
    void convert();

    int getPrecedence(const std::string);

    bool isNumber(const std::string);

    bool isOperator(const std::string);

    bool isFunction(const std::string);
};

#endif // INFIXTOPOSTFIXCONVERTER_H
