#include "../include/Calculator.h"
#include "../include/CalculatorException.h"
#include <iostream>

Calculator::Calculator() : pEvaluator(mBank)
{
    output = 0;
    errorState = false;
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
    catch (CalculatorException e)
    {
        errorState = true;
        errorMessage = e.what();
    }

    output = result;
}

void Calculator::setErrorState(bool error)
{
    errorState = error;
}
bool Calculator::getErrorState()
{
    return errorState;
}

std::string Calculator::getErrorMessage()
{
    return errorMessage;
}
