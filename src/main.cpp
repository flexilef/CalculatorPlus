#include <iostream>
#include <cstdlib>
#include <cmath>
#include "../include/InfixToPostfixConverter.h"
#include "../include/PostfixEvaluator.h"
#include "../include/MathTokenizer.h"
#include "../include/InfixToPostfixConverterTests.h"
#include "../include/PostfixEvaluatorTests.h"
#include "../include/MemoryBankTests.h"
#include "../include/Calculator.h"
#include "../include/MathUtil.h"
#include "../include/UnitTest.h"
#include "../include/CalculatorException.h"

int main()
{
    std::cout << "Hello world!\n\n";

    InfixToPostfixConverterTests testIP;
    PostfixEvaluatorTests testPE;
    MemoryBankTests testMB;

    UnitTest* tests[3];
    tests[0] = &testIP;
    tests[1] = &testPE;
    tests[2] = &testMB;

    for(int i = 0; i < 3; i++)
    {
        tests[i]->runTests();
        std::cout << "\n";
    }

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
