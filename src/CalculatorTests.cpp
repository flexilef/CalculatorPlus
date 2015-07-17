#include "../include/CalculatorTests.h"
#include <iostream>

CalculatorTests::CalculatorTests()
{
    //ctor
}

CalculatorTests::~CalculatorTests()
{
    //dtor
}

void CalculatorTests::runTests()
{
    applyAutoMultiplication_Number_Variable();
    applyAutoMultiplication_Number_Function();
    applyAutoMultiplication_Variable_Number();
    applyAutoMultiplication_Variable_Function();
    applyAutoMultiplication_Misc();

    std::cout << "CalculatorTests: Tests run    : " << totalTestsRun << "\n";
    std::cout << "CalculatorTests: Tests failed : " << totalTestsFailed << "\n";
}

void CalculatorTests::applyAutoMultiplication_Number_Variable()
{
    checkResult("2a", "2*a", "Auto Multiplication: single number, single variable");
    checkResult("2abc", "2*abc", "Auto Multiplication: single number, multiple variable");
    checkResult("2.5a", "2.5*a", "Auto Multiplication: decimal number, single variable");
    checkResult("2.5abc", "2.5*abc", "Auto Multiplication: decimal number, multiple variable");
    checkResult("-2.5a", "-2.5*a", "Auto Multiplication: negative number, single variable");
}

void CalculatorTests::applyAutoMultiplication_Number_Function()
{
    checkResult("2sin(30)", "2*sin(30)", "Auto Multiplication: single number, function");
    checkResult("2.5sin(30)", "2.5*sin(30)", "Auto Multiplication: decimal number,  function");
    checkResult("-2.5sin(30)", "-2.5*sin(30)", "Auto Multiplication: negative number, function");
}

void CalculatorTests::applyAutoMultiplication_Variable_Number()
{
    checkResult("a2", "a*2", "Auto Multiplication: single variable, single number");
    checkResult("abc2", "abc*2", "Auto Multiplication: multiple variable, single number");
    checkResult("a2.5", "a*2.5", "Auto Multiplication: single variable, decimal number");
    checkResult("abc2.5", "abc*2.5", "Auto Multiplication: multiple variable, decimal number");
    checkResult("a(-2.5)", "a*(-2.5)", "Auto Multiplication: single variable, negative number");
    checkResult("(a)(b)", "(a)*(b)", "Auto Multiplication: single variable, single number");

}

void CalculatorTests::applyAutoMultiplication_Variable_Function()
{
    checkResult("(b)sin(30)", "(b)*sin(30)", "Auto Multiplication: single variable, function");
    checkResult("(abc)sin(30)", "(abc)*sin(30)", "Auto Multiplication: multiple variable, function");
    checkResult("(3b)sin(30)", "(3*b)*sin(30)", "Auto Multiplication: number/variable, function");
    checkResult("(a)(b)sin(30)", "(a)*(b)*sin(30)", "Auto Multiplication: multiple variable, function");
}

void CalculatorTests::applyAutoMultiplication_Variable_Variable()
{
    checkResult("(a)(b)", "a*b", "Auto Multiplication: single variable, single variable");
    checkResult("(abc)(bcd)", "abc*bcd", "Auto Multiplication: multiple variable, multiple variable");
}

void CalculatorTests::applyAutoMultiplication_Misc()
{
    checkResult("1+2(2+3)", "1+2*(2+3)", "Auto Multiplication: expression, paren expression");
    checkResult("(1+2)(2+3)", "(1+2)*(2+3)", "Auto Multiplication: paren expression, paren expression");
}

void CalculatorTests::checkResult(const std::string& before, const std::string& after, const std::string& error)
{
    totalTestsRun++;
    calc.setInput(before);
    calc.applyAutoMultiplication();
    std::string result = calc.getInput();

    if(result != after)
    {
        totalTestsFailed++;
        std::cout << "Error found: " << error << "\n";
        std::cout << "before    : " << before << "\n";
        std::cout << "result     : " << result << "\n";
        std::cout << "answer     : " << after << "\n";
        std::cout << "\n";
    }
}
