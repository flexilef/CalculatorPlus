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

        void runTests();//prints out the totals for testsRun and failed
    protected:
    private:
        InfixToPostfixConverter converter;
        int totalTestsRun;
        int totalTestsFailed;

        //all these tests will be testing literals/variables/radix char which can be either negative/positive
        //test type -> type of inputs -> neg or pos

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
