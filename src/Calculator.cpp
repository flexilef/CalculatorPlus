#include <iostream>
#include <cmath>

#include "../include/Calculator.h"
#include "../include/CalculatorException.h"
#include "../include/DomainException.h"
#include "../include/SyntaxException.h"
#include "../include/MathException.h"
#include "../include/DivideByZeroException.h"

Calculator::Calculator() : pEvaluator(mBank)
{
    output = 0;
    calcState = RUNNINGSTATE;
    angleMode = MathUtil::DEGREES;
    pEvaluator.setAngleMode(angleMode);
    mBank.storeValueIntoVar("PI", M_PI);
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
    double result = 0;

    try
    {
        std::string postfix = ipConverter.convertToPostfix(input);
        result = pEvaluator.evaluatePostfix(postfix);
    }
    catch(CalculatorException& e)
    {
        calcState = ERRORSTATE;
        errorMessage = e.what();
    }
    catch(...)
    {
        calcState = ERRORSTATE;
        errorMessage = "Unknown error";
    }

    output = result;
}

void Calculator::setCalculatorState(CalculatorState state)
{
    calcState = state;
}
Calculator::CalculatorState Calculator::getCalculatorState()
{
    return calcState;
}

std::string Calculator::getErrorMessage()
{
    return errorMessage;
}

void Calculator::setAngleMode(MathUtil::AngleMode mode)
{
    angleMode = mode;
    pEvaluator.setAngleMode(mode);
}
