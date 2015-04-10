#include "../include/InfixToPostfixConverterTests.h"
#include <iostream>

InfixToPostfixConverterTests::InfixToPostfixConverterTests()
{
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
    convertToPostfix_whiteSpace_returnPostfixExpression();

    std::cout << "InfixToPostfixConverterTests: Tests run    : " << totalTestsRun << "\n";
    std::cout << "InfixToPostfixConverterTests: Tests failed : " << totalTestsFailed << "\n";
}

void InfixToPostfixConverterTests::convertToPostfix_binaryOperators_returnPostfixExpression()
{
    //addition
    checkPostfix("1+2", "1 2 +", "binary operator: addition: single digit");
    checkPostfix("12+34", "12 34 +", "binary operator: addition: multiple digit");
    checkPostfix("1.2+34.56", "1.2 34.56 +", "binary operator: addition: decimal point");
    checkPostfix("a+bc", "a bc +", "binary operator: addition: variable");
    checkPostfix("-1+-2", "1 ~ 2 ~ +", "binary operator: addition: negative");
    checkPostfix("-a+-bc", "a ~ bc ~ +", "binary operator: addition: negative variable");

    //subtraction
    checkPostfix("1-2", "1 2 -", "binary operator: subtraction: single digit");
    checkPostfix("12-34", "12 34 -", "binary operator: subtraction: multiple digit");
    checkPostfix("1.2-34.56", "1.2 34.56 -", "binary operator: subtraction: decimal point");
    checkPostfix("a-bc", "a bc -", "binary operator: subtraction: variable");
    checkPostfix("-1--2", "1 ~ 2 ~ -", "binary operator: subtraction: negative");
    checkPostfix("-a--bc", "a ~ bc ~ -", "binary operator: subtraction: negative variable");

    //multiplication
    checkPostfix("1*2", "1 2 *", "binary operator: multiplication: single digit");
    checkPostfix("12*34", "12 34 *", "binary operator: multiplication: multiple digit");
    checkPostfix("1.2*34.56", "1.2 34.56 *", "binary operator: multiplication: decimal point");
    checkPostfix("a*bc", "a bc *", "binary operator: multiplication: variable");
    checkPostfix("-1*-2", "1 ~ 2 ~ *", "binary operator: multiplication: negative");
    checkPostfix("-a*-bc", "a ~ bc ~ *", "binary operator: multiplication: negative variable");

    //division
    checkPostfix("1/2", "1 2 /", "binary operator: division: single digit");
    checkPostfix("12/34", "12 34 /", "binary operator: division: multiple digit");
    checkPostfix("1.2/34.56", "1.2 34.56 /", "binary operator: division: decimal point");
    checkPostfix("a/bc", "a bc /", "binary operator: division: variable");
    checkPostfix("-1/-2", "1 ~ 2 ~ /", "binary operator: division: negative");
    checkPostfix("-a/-bc", "a ~ bc ~ /", "binary operator: division: negative variable");

    //power
    checkPostfix("1^2", "1 2 ^", "binary operator: power: single digit");
    checkPostfix("12^34", "12 34 ^", "binary operator: power: multiple digit");
    checkPostfix("1.2^34.56", "1.2 34.56 ^", "binary operator: power: decimal point");
    checkPostfix("a^bc", "a bc ^", "binary operator: power: variable");
    checkPostfix("-1^2", "1 2 ^ ~", "binary operator: power: negative base");
    checkPostfix("1^-2", "1 2 ~ ^", "binary operator: power: negative exponent");
    checkPostfix("-1^-2", "1 2 ~ ^ ~", "binary operator: power: negative exponent and base");
    checkPostfix("-a^-bc", "a bc ~ ^ ~", "binary operator: power: negative variable");
    checkPostfix("1^2^3", "1 2 ^ 3 ^", "binary operator: power: associativity");

    //mod
    checkPostfix("1mod2", "1 2 mod", "binary operator: mod: single digit");
    checkPostfix("12mod34", "12 34 mod", "binary operator: mod: multiple digit");
    checkPostfix("1.2mod34.56", "1.2 34.56 mod", "binary operator: mod: decimal point");
    checkPostfix("(a)mod(bc)", "a bc mod", "binary operator: mod: variable");
    checkPostfix("-1mod-2", "1 ~ 2 ~ mod", "binary operator: mod: negative: will be fixed when tokenizer is fixed.");
    checkPostfix("(-a)mod(-bc)", "a ~ bc ~ mod", "binary operator: mod: negative variable");

    //assignment
    checkPostfix("a=1", "a 1 =", "binary operator: assignment: single digit");
    checkPostfix("a=12", "a 12 =", "binary operator: assignment: multiple digit");
    checkPostfix("a=1.23", "a 1.23 =", "binary operator: assignment: decimal point");
    checkPostfix("a=bcd", "a bcd =", "binary operator: assignment: variable");
    checkPostfix("a=-123", "a 123 ~ =", "binary operator: assignment: negative");
    checkPostfix("a=-bcd", "a bcd ~ =", "binary operator: assignment: negative variable");
    checkPostfix("abc=123", "abc 123 =", "binary operator: assignment: multiple letter");
    checkPostfix("a=1E2", "a 1 2 E =", "binary operator: assignment: scientific notation");
    checkPostfix("a=(1+2)*(3-4)", "a 1 2 + 3 4 - * =", "binary operator: assignment: calculation");

    //E - scientific notation
    checkPostfix("1E2", "1 2 E", "binary operator: E: single digit");
    checkPostfix("12E34", "12 34 E", "binary operator: E: multiple digit");
    checkPostfix("1.2E34.56", "1.2 34.56 E", "binary operator: E: decimal point");//no such thing remove?
    checkPostfix("-1E2", "1 ~ 2 E", "binary operator: E: negative coefficient");
    checkPostfix("1E-2", "1 2 ~ E", "binary operator: E: negative exponent");
    checkPostfix("(a)E5", "a 5 E", "binary operator: E: coefficient variable 2");
    checkPostfix("5E(a)", "5 a E", "binary operator: E: exponent variable");
    checkPostfix("(-a)E5", "a ~ 5 E", "binary operator: E: negative coefficient variable");
    checkPostfix("5E(-a)", "5 a ~ E", "binary operator: E: negative exponent variable");
    checkPostfix("(a)E(b)", "a b E", "binary operator: E: exponent and coefficient variable");

    //known tests failed
    //checkPostfix("aEb", "a b E", "binary operator: E: exponent and coefficient variable");
}

void InfixToPostfixConverterTests::convertToPostfix_unaryOperators_returnPostfixExpression()
{
    //unary negation
    checkPostfix("-1", "1 ~","unary operator: negation: single digit");
    checkPostfix("-12", "12 ~","unary operator: negation: multiple digit");
    checkPostfix("-1.2", "1.2 ~","unary operator: negation: decimal point");
    checkPostfix("-a", "a ~","unary operator: negation: variable");
    checkPostfix("-abc", "abc ~","unary operator: negation: multiple variable");
    checkPostfix("--1", "1 ~ ~","unary operator: negation: double negative");
    checkPostfix("--abc", "abc ~ ~","unary operator: negation: double negative variable");

    //factorial
    checkPostfix("1!", "1 !","unary operator: factorial: single digit");
    checkPostfix("12!", "12 !","unary operator: factorial: multiple digit");
    checkPostfix("1.2!", "1.2 !","unary operator: factorial: decimal point");
    checkPostfix("a!", "a !","unary operator: factorial: variable");
    checkPostfix("abc!", "abc !","unary operator: factorial: multiple variable");
    checkPostfix("-1!", "1 ~ !","unary operator: factorial: negative");
    checkPostfix("1!!", "1 ! !","unary operator: factorial: double factorial");
    checkPostfix("abc!!", "abc ! !","unary operator: factorial: double negative variable");

    //percent
    checkPostfix("1%", "1 %","unary operator: percent: single digit");
    checkPostfix("12%", "12 %","unary operator: percent: multiple digit");
    checkPostfix("1.2%", "1.2 %","unary operator: percent: decimal point");
    checkPostfix("a%", "a %","unary operator: percent: variable");
    checkPostfix("abc%", "abc %","unary operator: percent: multiple variable");
    checkPostfix("-1%", "1 ~ %","unary operator: percent: negative");
    checkPostfix("1%%", "1 % %","unary operator: percent: double factorial");
    checkPostfix("abc%%", "abc % %","unary operator: percent: double negative variable");
}

void InfixToPostfixConverterTests::convertToPostfix_constants_returnPostfixExpression()
{
    //numbers
    checkPostfix("1", "1 ", "constants: single digit");
    checkPostfix("12", "12 ", "constants: multiple digit");
    checkPostfix("1.23", "1.23 ", "constants: decimal point");

    //variables
    checkPostfix("a", "a ", "constants: single variable");
    checkPostfix("abc", "abc ", "constants: multiple variable");
    checkPostfix("abEfg", "abEfg ","constants: variable name with operator name: E: middle");
    checkPostfix("abcE", "abcE ","constants: variable name with operator name: E: end");
    checkPostfix("abmodc", "abmodc ","constants: variable name with operator name: mod");
    checkPostfix("abcmod", "abcmod ","constants: variable name with operator name: mod");
    checkPostfix("Vsinar", "Vsinar ","constants: variable name with function name: sin");
    checkPostfix("Varsin", "Varsin ","constants: variable name with function name: sin");

    //known tests failed
    //checkPostfix("Eabc", "Eabc ","constants: variable name with operator name: E: front");
    //checkPostfix("modabc", "modabc ","constants: variable name with operator name: mod: ");
    //checkPostfix("sinVar", "sinVar ","constants: variable name with function name: sin");
}

void InfixToPostfixConverterTests::convertToPostfix_basicFunctions_returnPostfixExpression()
{
    //abs
    checkPostfix("abs(1)", "1 abs", "basic functions: abs(): single digit");
    checkPostfix("abs(12)", "12 abs", "basic functions: abs(): multiple digit");
    checkPostfix("abs(1.23)", "1.23 abs", "basic functions: abs(): decimal point");
    checkPostfix("abs(abc)", "abc abs", "basic functions: abs(): variable digit");
    checkPostfix("abs(-1)", "1 ~ abs", "basic functions: abs(): negative argument");
    checkPostfix("abs(-abc)", "abc ~ abs", "basic functions: abs(): negative variable");
    checkPostfix("-abs(-1)", "1 ~ abs ~", "basic functions: abs(): negative function");

    //cbrt
    checkPostfix("cbrt(1)", "1 cbrt", "basic functions: cbrt(): single digit");
    checkPostfix("cbrt(12)", "12 cbrt", "basic functions: cbrt(): multiple digit");
    checkPostfix("cbrt(1.23)", "1.23 cbrt", "basic functions: cbrt(): decimal point");
    checkPostfix("cbrt(abc)", "abc cbrt", "basic functions: cbrt(): variable digit");
    checkPostfix("cbrt(-1)", "1 ~ cbrt", "basic functions: cbrt(): negative argument");
    checkPostfix("cbrt(-abc)", "abc ~ cbrt", "basic functions: cbrt(): negative variable");
    checkPostfix("-cbrt(-1)", "1 ~ cbrt ~", "basic functions: cbrt(): negative function");

    //exp
    checkPostfix("exp(1)", "1 exp", "basic functions: exp(): single digit");
    checkPostfix("exp(12)", "12 exp", "basic functions: exp(): multiple digit");
    checkPostfix("exp(1.23)", "1.23 exp", "basic functions: exp(): decimal point");
    checkPostfix("exp(abc)", "abc exp", "basic functions: exp(): variable digit");
    checkPostfix("exp(-1)", "1 ~ exp", "basic functions: exp(): negative argument");
    checkPostfix("exp(-abc)", "abc ~ exp", "basic functions: exp(): negative variable");
    checkPostfix("-exp(-1)", "1 ~ exp ~", "basic functions: exp(): negative function");

    //ln
    checkPostfix("ln(1)", "1 ln", "basic functions: ln(): single digit");
    checkPostfix("ln(12)", "12 ln", "basic functions: ln(): multiple digit");
    checkPostfix("ln(1.23)", "1.23 ln", "basic functions: ln(): decimal point");
    checkPostfix("ln(abc)", "abc ln", "basic functions: ln(): variable digit");
    checkPostfix("ln(-1)", "1 ~ ln", "basic functions: ln(): negative argument");
    checkPostfix("ln(-abc)", "abc ~ ln", "basic functions: ln(): negative variable");
    checkPostfix("-ln(-1)", "1 ~ ln ~", "basic functions: ln(): negative function");

    //log
    checkPostfix("log(1)", "1 log", "basic functions: log(): single digit");
    checkPostfix("log(12)", "12 log", "basic functions: log(): multiple digit");
    checkPostfix("log(1.23)", "1.23 log", "basic functions: log(): decimal point");
    checkPostfix("log(abc)", "abc log", "basic functions: log(): variable digit");
    checkPostfix("log(-1)", "1 ~ log", "basic functions: log(): negative argument");
    checkPostfix("log(-abc)", "abc ~ log", "basic functions: log(): negative variable");
    checkPostfix("-log(-1)", "1 ~ log ~", "basic functions: log(): negative function");

    //sqrt
    checkPostfix("sqrt(1)", "1 sqrt", "basic functions: sqrt(): single digit");
    checkPostfix("sqrt(12)", "12 sqrt", "basic functions: sqrt(): multiple digit");
    checkPostfix("sqrt(1.23)", "1.23 sqrt", "basic functions: sqrt(): decimal point");
    checkPostfix("sqrt(abc)", "abc sqrt", "basic functions: sqrt(): variable digit");
    checkPostfix("sqrt(-1)", "1 ~ sqrt", "basic functions: sqrt(): negative argument");
    checkPostfix("sqrt(-abc)", "abc ~ sqrt", "basic functions: sqrt(): negative variable");
    checkPostfix("-sqrt(-1)", "1 ~ sqrt ~", "basic functions: sqrt(): negative function");
}

void InfixToPostfixConverterTests::convertToPostfix_trigFunctions_returnPostfixExpression()
{
    //asin
    checkPostfix("asin(1)", "1 asin", "trig functions: asin(): single digit");
    checkPostfix("asin(12)", "12 asin", "basic functions: asin(): multiple digit");
    checkPostfix("asin(1.23)", "1.23 asin", "basic functions: asin(): decimal point");
    checkPostfix("asin(abc)", "abc asin", "basic functions: asin(): variable digit");
    checkPostfix("asin(-1)", "1 ~ asin", "basic functions: asin(): negative argument");
    checkPostfix("asin(-abc)", "abc ~ asin", "basic functions: asin(): negative variable");
    checkPostfix("-asin(-1)", "1 ~ asin ~", "basic functions: asin(): negative function");

    //tan
    checkPostfix("tan(1)", "1 tan", "trig functions: tan(): single digit");
    checkPostfix("tan(12)", "12 tan", "basic functions: tan(): multiple digit");
    checkPostfix("tan(1.23)", "1.23 tan", "basic functions: tan(): decimal point");
    checkPostfix("tan(abc)", "abc tan", "basic functions: tan(): variable digit");
    checkPostfix("tan(-1)", "1 ~ tan", "basic functions: tan(): negative argument");
    checkPostfix("tan(-abc)", "abc ~ tan", "basic functions: tan(): negative variable");
    checkPostfix("-tan(-1)", "1 ~ tan ~", "basic functions: tan(): negative function");
}

void InfixToPostfixConverterTests::convertToPostfix_miscInputs_returnPostfixExpression()
{
    //order of operations/trig functions/parentheses/...etc
    checkPostfix("(5+8*sin(2*15))/(2+tan(45))", "5 8 2 15 * sin * + 2 45 tan + /", "misc error");
    checkPostfix("(sin(2*15)*8+5)/(tan(45)+2)", "2 15 * sin 8 * 5 + 45 tan 2 + /", "misc error");
    checkPostfix("(3*ln(e^2)+8*cos(60))/(3*4^0.5-1)", "3 e 2 ^ ln * 8 60 cos * + 3 4 0.5 ^ * 1 - /", "misc error");
}

void InfixToPostfixConverterTests::convertToPostfix_whiteSpace_returnPostfixExpression()
{
    //constant
    checkPostfix(" 1  ", "1 ", "white space: constant: number");
    checkPostfix(" 1.23  ", "1.23 ", "white space: constant: decimal point");
    checkPostfix(" abc  ", "abc ", "white space: constant: variable");

    //binary
    checkPostfix("1 +  2", "1 2 +", "white space: binary: addition");
    checkPostfix("1 -  2", "1 2 -", "white space: binary: subtraction");
    checkPostfix("1 *  2", "1 2 *", "white space: binary: multiplication");
    checkPostfix("1 /  2", "1 2 /", "white space: binary: division");
    checkPostfix("1 ^  2", "1 2 ^", "white space: binary: power");

    //unary
    checkPostfix("- 1", "1 ~", "white space: after negative");
    checkPostfix(" -1", "1 ~", "white space: before negative: will be fixed when tokenizer is fixed");

    //functions
    checkPostfix("sin( 30 )", "30 sin", "white space: trig functions: in argument");
    checkPostfix("cos  (30)", "30 cos", "white space: trig functions: before parenthesis");
}

///helpers

void InfixToPostfixConverterTests::checkPostfix(const std::string &infix, const std::string &postfix, const std::string &error)
{
    totalTestsRun++;
    std::string output = converter.convertToPostfix(infix);

    if(removeExtraWhiteSpace(output) != postfix)
    {
        totalTestsFailed++;
        std::cout << "Error found: " << error << "\n";
        std::cout << "Infix  : " << infix << "\n";
        std::cout << "Output : " << output << "\n";
        std::cout << "Postfix: " << postfix << "\n";
        std::cout << "\n";
    }
}

std::string InfixToPostfixConverterTests::removeExtraWhiteSpace(const std::string &input)
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
