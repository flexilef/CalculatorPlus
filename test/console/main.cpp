#include <iostream>

#include "../../include/core/Calculator.h"
#include "../../include/core/InfixToPostfixConverter.h"
#include "../../include/core/PostfixEvaluator.h"
#include "../../include/core/MemoryBank.h"
#include "../../include/core/MathTokenizer.h"

int main()
{
    Calculator calc;

    //std::string testStr = "";
    //MemoryBank mb;
    //MathTokenizer tk(testStr);
    //InfixToPostfixConverter in;
    //PostfixEvaluator pe(mb);

    while(true)
    {
        std::string str;
        std::cout << "Enter: ";
        std::getline(std::cin, str);
        calc.setInput(str);
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
