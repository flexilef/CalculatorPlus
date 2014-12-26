#ifndef INFIXTOPOSTFIXCONVERTERTESTS_H
#define INFIXTOPOSTFIXCONVERTERTESTS_H

#include <vector>
#include "../include/InfixToPostfixConverter.h"

class InfixToPostfixConverterTests
{
    public:
        /** Default constructor */
        InfixToPostfixConverterTests();
        /** Default destructor */
        virtual ~InfixToPostfixConverterTests();

        void runTests();
    protected:
    private:
        InfixToPostfixConverter testConverter;
        std::vector<std::string> testInputs;

        std::string convertToPostfix_emptyStringInput_returnEmptyString();
        std::string convertToPostfix_postfixValidity_returnPostfixExpression();
};

#endif // INFIXTOPOSTFIXCONVERTERTESTS_H
