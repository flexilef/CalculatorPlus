#include <iostream>
#include "../include/InfixToPostfixConverter.h"
#include "../include/PostfixEvaluator.h"
#include "../include/MathTokenizer.h"
#include "../include/InfixToPostfixConverterTests.h"
#include "../include/PostfixEvaluatorTests.h"
#include "../include/MemoryBankTests.h"

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

    //t.setInput("-1--2");
    //t.dumpTokens();
    //cout << ip.convertToPostfix("-a--b") << endl;
    //cout << pe.evaluatePostfix("1 ~ 2 ~ -");

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
