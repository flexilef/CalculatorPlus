#include <iostream>

#include "../../include/core/Calculator.h"
#include "../include/CalculatorTests.h"
#include "../include/InfixToPostfixConverterTests.h"
#include "../include/PostfixEvaluatorTests.h"
#include "../include/MemoryBankTests.h"

int main()
{
    InfixToPostfixConverterTests testIP;
    PostfixEvaluatorTests testPE;
    MemoryBankTests testMB;
    CalculatorTests testC;

    UnitTest* tests[4];
    tests[0] = &testIP;
    tests[1] = &testPE;
    tests[2] = &testMB;
    tests[3] = &testC;

    for(int i = 0; i < 4; i++)
    {
        tests[i]->runTests();
        std::cout << "\n";
    }

    return 0;
}
