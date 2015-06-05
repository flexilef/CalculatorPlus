#include "../include/Calculator.h"
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
    double result = pEvaluator.evaluatePostfix(postfix);

    output = result;
}
