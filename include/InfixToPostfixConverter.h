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

        int getPrecedence(char);

        bool isOperand(char);

        bool isOperator(char);
};

#endif // INFIXTOPOSTFIXCONVERTER_H
