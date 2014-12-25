#ifndef INFIXTOPOSTFIXCONVERTER_H
#define INFIXTOPOSTFIXCONVERTER_H

#include "InputConverter.h"
#include "MathTokenizer.h"

class InfixToPostfixConverter : public InputConverter
{
public:
    /** Default constructor */
    InfixToPostfixConverter();
    /** Default destructor */
    virtual ~InfixToPostfixConverter();

    std::string convertToPostfix(const std::string&);

private:
    MathTokenizer tokenizer;

    void convert();
};

#endif // INFIXTOPOSTFIXCONVERTER_H
