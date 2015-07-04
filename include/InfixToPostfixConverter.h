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

    std::string convertToPostfix(const std::string&);

private:
    void convert();
    bool isInfix(const std::string);
};

#endif // INFIXTOPOSTFIXCONVERTER_H
