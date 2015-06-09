#include "../include/Calculator.h"
#include "../include/CalculatorException.h"
#include <iostream>

Calculator::Calculator() : pEvaluator(mBank)
{
    output = 0;
}

Calculator::~Calculator()
{
    //dtor
}

void Calculator::getUserInput()
{
    std::string str;
    std::cout << "Enter: ";
    std::getline(std::cin, str);
    setInput(str);
}

std::string Calculator::getInput()
{
    return input;
}


void Calculator::setInput(const std::string& str)
{
    input = str;
}

double Calculator::getOutput()
{
    return output;
}

double Calculator::calculate()
{
    std::string postfix = ipConverter.convertToPostfix(input);
    double result = 0;

    try
    {
        result = pEvaluator.evaluatePostfix(postfix);
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what();
    }

    output = result;
}
