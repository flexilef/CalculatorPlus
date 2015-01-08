#include <iostream>
#include "../include/InfixToPostfixConverter.h"
#include "../include/PostfixEvaluator.h"
#include "../include/MathTokenizer.h"
#include "../include/InfixToPostfixConverterTests.h"
#include "../include/PostfixEvaluatorTests.h"

#include <cstdlib>
#include <cmath>
using namespace std;
std::string removeExtraWhiteSpace(std::string);

int main()
{
    cout << "Hello world!" << endl << endl;

    InfixToPostfixConverter ip;
    PostfixEvaluator pe;
    MathTokenizer t;

    //testing
    InfixToPostfixConverterTests testIP;
    testIP.runTests();

    cout << "\n";

    PostfixEvaluatorTests testPE;
    testPE.runTests();

    cout << "\n";

    //cout << removeExtraWhiteSpace(ip.convertToPostfix("12.4^-3.7")) << "\n";

    t.setInput("1 %");
    t.dumpTokens();

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
