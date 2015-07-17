#include <iostream>

#include "../../include/core/Calculator.h"

int main()
{
    Calculator calc;

    while(true)
    {
        calc.getUserInput();
        calc.calculate();

        if(calc.getCalculatorState() == Calculator::ERRORSTATE)
        {
            std::cout << calc.getErrorMessage() << "\n";
            calc.setCalculatorState(Calculator::DEFAULTSTATE);
        }
        else
            std::cout << "answer: " << calc.getOutput() << "\n";
    }

    return 0;
}
