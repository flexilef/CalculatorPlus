#include <iostream>
#include "../include/InfixToPostfixConverter.h"
#include "../include/PostfixEvaluator.h"
#include "../include/MathTokenizer.h"
#include "../include/InfixToPostfixConverterTests.h"
#include "../include/PostfixEvaluatorTests.h"
#include "../include/MemoryBankTests.h"
#include "../include/Calculator.h"
#include "../include/MathUtil.h"

#include <cstdlib>
#include <cmath>
using namespace std;
std::string removeExtraWhiteSpace(std::string);

int main()
{
    cout << "Hello world!" << endl << endl;

    MemoryBank mb;
    InfixToPostfixConverter ip;
    PostfixEvaluator pe(mb);
    MathTokenizer t;

    InfixToPostfixConverterTests testIP;
    testIP.runTests();

    cout << "\n";

    PostfixEvaluatorTests testPE;
    testPE.runTests();

    cout << "\n";

    MemoryBankTests testMB;
    testMB.runTests();

    //cout << ip.convertToPostfix("a=5");
    //cout << pe.evaluatePostfix("a 5 =");
    //t.setInput("a=5");
    //t.dumpTokens();

    Calculator calc;

    while(true)
    {
        calc.getUserInput();
        cout << "answer: " << calc.calculate() << "\n";
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
