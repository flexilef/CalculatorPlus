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

using namespace std;
std::string removeExtraWhiteSpace(std::string);

int main()
{
    cout << "Hello world!" << endl << endl;

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
        cout << "\n";
    }

    Calculator calc;

    MemoryBank m;
    InfixToPostfixConverter i;
    PostfixEvaluator p(m);

/*
    try
    {
        string str = i.convertToPostfix("1*2+");
        double ans = p.evaluatePostfix(str);

        cout << "STR: " << str << "\n";
        cout << "ANS: " << ans << "\n";
    }
    catch(CalculatorException& e)
    {
        cout << e.what();
    }
*/
    while(true)
    {
        calc.getUserInput();
        calc.calculate();
        if(calc.getCalculatorState() == Calculator::ERRORSTATE)
        {
            cout << calc.getErrorMessage() << "\n";
            calc.setCalculatorState(Calculator::RUNNINGSTATE);
        }
        else
            cout << "answer: " << calc.getOutput() << "\n";
    }

    return 0;
}

std::string removeExtraWhiteSpace(std::string str)
{
    std::string output;
    int length = str.length();

    for(int i = 0; i < length; i++)
    {
        if(str.substr(i, 1) != " ")
        {
            output+=str.substr(i, 1);
        }
        else
        {
            //if the last char in output is not a space then add one
            if(output.substr(output.length()-1, 1) != " ")
                output+=" ";
        }
    }

    return output;
}
