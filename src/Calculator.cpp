#include "../include/Calculator.h"
#include <iostream>

Calculator::Calculator() : pEvaluator(mBank)
{
    answer = 0;
}

Calculator::~Calculator()
{
    //dtor
}

void Calculator::getUserInput()
{
    std::cout << "Enter: ";
    std::getline(std::cin, input);
}

double Calculator::calculate()
{
    std::string postfix = ipConverter.convertToPostfix(input);
    double result = pEvaluator.evaluatePostfix(postfix);

    return result;
}
