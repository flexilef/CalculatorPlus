#include "../include/InfixToPostfixConverterTests.h"

InfixToPostfixConverterTests::InfixToPostfixConverterTests()
{
    totalTestsRun = 0;
    totalTestsFailed = 0;
}

InfixToPostfixConverterTests::~InfixToPostfixConverterTests()
{
    //dtor
}

void InfixToPostfixConverterTests::runTests()
{
    convertToPostfix_constants_returnPostfixExpression();
    convertToPostfix_unaryOperators_returnPostfixExpression();
    convertToPostfix_binaryOperators_returnPostfixExpression();
    convertToPostfix_basicFunctions_returnPostfixExpression();
    convertToPostfix_trigFunctions_returnPostfixExpression();
    convertToPostfix_miscInputs_returnPostfixExpression();

    std::cout << "Total number of tests run: " << totalTestsRun << "\n";
    std::cout << "Total number of tests failed: " << totalTestsFailed << "\n";
}

void InfixToPostfixConverterTests::convertToPostfix_binaryOperators_returnPostfixExpression()
{
    //binary operator: single digits
    if(!checkPostfix("1+2", "1 2 +"))
        std::cout << "binary operator: addition: single digit error." << "\n";
}

void InfixToPostfixConverterTests::convertToPostfix_unaryOperators_returnPostfixExpression()
{
    //unary operator: single digit
    if(!checkPostfix("-1", "1 ~"))
        std::cout << "unary operator: negation: single digit error." << "\n";
}

void InfixToPostfixConverterTests::convertToPostfix_constants_returnPostfixExpression()
{
    //constants: single digit
    if(!checkPostfix("1", "1 "))
        std::cout << "constants: single digit error" << "\n";
}

void InfixToPostfixConverterTests::convertToPostfix_basicFunctions_returnPostfixExpression()
{
    //basic functions: ln(): single digit
    if(!checkPostfix("ln(1)", "1 ln"))
        std::cout << "basic functions: ln(): single digit error." << "\n";
}

void InfixToPostfixConverterTests::convertToPostfix_trigFunctions_returnPostfixExpression()
{
    //trig functions: sin(): single digit
    if(!checkPostfix("sin(1)", "1 sin"))
        std::cout << "trig functions: sin(): single digit error." << "\n";
}

void InfixToPostfixConverterTests::convertToPostfix_miscInputs_returnPostfixExpression()
{
    checkPostfix("(5 + 8 * sin(2 * 15)) / (2 + tan(45))", "5 8 2 15 * sin * + 2 45 tan + /");
    checkPostfix("(sin(2 * 15) * 8 + 5) / (tan(45) + 2)", "2 15 * sin 8 * 5 + 45 tan 2 + /");
    checkPostfix("(3 * ln(e^2) + 8 * cos(60)) / (3 * 4^0.5 - 1)", "3 e 2 ^ ln * 8 60 cos * + 3 4 0.5 ^ * 1 - /");
}

///helpers

bool InfixToPostfixConverterTests::checkPostfix(const std::string infix, const std::string postfix)
{
    totalTestsRun++;

    if(removeExtraWhiteSpace(converter.convertToPostfix(infix)) != postfix)
    {
        totalTestsFailed++;
        return false;
    }

    return true;
}

std::string InfixToPostfixConverterTests::removeExtraWhiteSpace(const std::string input)
{
    std::string output;
    int length = input.length();

    for(int i = 0; i < length; i++)
    {
        if(input.substr(i, 1) != " ")
        {
            output+=input.substr(i, 1);
        }
        else
        {
            //if the last char in output is not a space then add one
            if(output.substr(output.length()-1, 1) != " ")
                output+=" ";
        }
    }

    return output;
}
