#ifndef INFIXTOPOSTFIXCONVERTERTESTS_H
#define INFIXTOPOSTFIXCONVERTERTESTS_H

#include <vector>
#include "../../include/core/InfixToPostfixConverter.h"
#include "../include/UnitTest.h"

class InfixToPostfixConverterTests : public UnitTest
{
    public:
        /** Default constructor */
        InfixToPostfixConverterTests();
        /** Default destructor */
        virtual ~InfixToPostfixConverterTests();
        void runTests();

    protected:

    private:
        InfixToPostfixConverter converter;

        //tests
        void convertToPostfix_constants_returnPostfixExpression();
        void convertToPostfix_unaryOperators_returnPostfixExpression();
        void convertToPostfix_binaryOperators_returnPostfixExpression();
        void convertToPostfix_basicFunctions_returnPostfixExpression();
        void convertToPostfix_trigFunctions_returnPostfixExpression();
        void convertToPostfix_miscInputs_returnPostfixExpression();
        void convertToPostfix_whiteSpace_returnPostfixExpression();

        //helpers
        void checkPostfix(const std::string&, const std::string&, const std::string&);
        std::string removeExtraWhiteSpace(const std::string&);
};

#endif // INFIXTOPOSTFIXCONVERTERTESTS_H
