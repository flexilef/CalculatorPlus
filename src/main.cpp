#include <iostream>
#include "../include/InfixToPostfixConverter.h"
#include "../include/MathTokenizer.h"
#include "../include/InfixToPostfixConverterTests.h"

#include <stdlib.h>
using namespace std;
std::string removeExtraWhiteSpace(std::string);

int main()
{
    cout << "Hello world!" << endl << endl;

    InfixToPostfixConverter ip;
    MathTokenizer t;
    cout << "Testing InfixToPostfixConverter... \n\n";
    /*
        cout << "1: Simple calculations with single digits \n";
        cout << "infix  : 1+2-3*4/5 \n";
        cout << "postfix: 12+34*5/- \n";
        cout << "output1: " << removeWhiteSpace(ip.convertToPostfix("1+2-3*4/5")) << "\n";
        cout << "output2: " << ip.convertToPostfix("1+2-3*4/5") << "\n";
        cout << endl;

        cout << "2: Simple calculations with multiple digits \n";
        cout << "infix  : 1+23-456*78/9 \n";
        cout << "postfix: 123+45678*9/- \n";
        cout << "output1: " << removeWhiteSpace(ip.convertToPostfix("1+23-456*78/9")) << "\n";
        cout << "output2: " << ip.convertToPostfix("1+23-456*78/9") << "\n";
        cout << endl;

        cout << "3: Simple calculations with variables \n";
        cout << "infix  : a+23-b*78/c \n";
        cout << "postfix: a23+b78*c/- \n";
        cout << "output1: " << removeWhiteSpace(ip.convertToPostfix("a+23-b*78/c")) << "\n";
        cout << "output2: " << ip.convertToPostfix("a+23-b*78/c") << "\n";
        cout << endl;

        cout << "4: Trig functions with numbers\n";
        cout << "infix  : sin(5)+cos(20.7)*tan(35) \n";
        cout << "postfix: 5sin20.7cos35tan*+ \n";
        cout << "output1: " << removeWhiteSpace(ip.convertToPostfix("sin(5)+cos(20.7)*tan(35)")) << "\n";
        cout << "output2: " << ip.convertToPostfix("sin(5)+cos(20.7)*tan(35)") << "\n";
        cout << endl;

        cout << "5: Trig functions with variables\n";
        cout << "infix  : sin(a)+cos(20.77)*tan(number) \n";
        cout << "postfix: asin20.77cosnumbertan*+ \n";
        cout << "output1: " << removeWhiteSpace(ip.convertToPostfix("sin(a)+cos(20.77)*tan(number)")) << "\n";
        cout << "output2: " << ip.convertToPostfix("sin(a)+cos(20.77)*tan(number)") << "\n";
        cout << endl;

        //test cases

        cout << "1: \n";
        cout << "infix: ((a*b)+(c/d)) \n";
        cout << "postfix: a b * c d / +\n";
        cout << "output: " << ip.convertToPostfix("((a*b)+(c/d))") << "\n";
        cout << endl;

        cout << "2: \n";
        cout << "infix: ((A*(B+C))/D) \n";
        cout << "postfix: A B C + * D / \n";
        cout << "output: " << ip.convertToPostfix("((A*(B+C))/D)") << "\n";
        cout << endl;

        cout << "3: \n";
        cout << "infix: (A*(B+(C/D))) \n";
        cout << "postfix: A B C D / + * \n";
        cout << "output: " << ip.convertToPostfix("(A*(B+(C/D)))") << "\n";
        cout << endl;

        cout << "4: \n";
        cout << "infix: (4 + 2 * 5) / (1 + 3 * 2) \n";
        cout << "postfix: 4 2 5 * + 1 3 2 * + / \n";
        cout << "output: " << ip.convertToPostfix("(4 + 2 * 5) / (1 + 3 * 2)") << "\n";
        cout << endl;

        cout << "5: \n";
        cout << "infix: (2 * 5 + 4 )/(3 * 2 + 1) \n";
        cout << "postfix: 2 5 * 4 + 3 2 * 1 + / \n";
        cout << "output: " << ip.convertToPostfix("(2 * 5 + 4 )/(3 * 2 + 1)") << "\n";
        cout << endl;

        cout << "6: \n";
        cout << "infix: (5 + 8 * sin(2 * 15)) / (2 + tan(45)) \n";
        cout << "postfix: 5 8 2 15 * sin * + 2 45 tan + / \n";
        cout << "output: " << ip.convertToPostfix("(5 + 8 * sin(2 * 15)) / (2 + tan(45))") << "\n";
        cout << endl;

        cout << "7: \n";
        cout << "infix: (sin(2 * 15) * 8 + 5) / (tan(45) + 2) \n";
        cout << "postfix: 2 15 * sin 8 * 5 + 45 tan 2 + / \n";
        cout << "output: " << ip.convertToPostfix("(sin(2 * 15) * 8 + 5) / (tan(45) + 2)") << "\n";
        cout << endl;

        cout << "8: \n";
        cout << "infix: (3 * ln(e^2) + 8 * cos(60)) / (3 * 4^0.5 - 1) \n";
        cout << "postfix: 3 e 2 ^ ln * 8 60 cos * + 3 4 0.5 ^ * 1 - / \n";
        cout << "output: " << ip.convertToPostfix("(3 * ln(e^2) + 8 * cos(60)) / (3 * 4^0.5 - 1)") << "\n";
        cout << endl;


        cout << ip.convertToPostfix("1^2") << "\n";
        cout << ip.convertToPostfix("1^2^3") << "\n";
        cout << ip.convertToPostfix("-1^2") << "\n";
        cout << ip.convertToPostfix("-(1^2)") << "\n";
        cout << ip.convertToPostfix("1^-2") << "\n";
        cout << ip.convertToPostfix("-2^-3") << "\n";
        */

    InfixToPostfixConverterTests testIP;
    testIP.runTests();
    cout << removeExtraWhiteSpace(ip.convertToPostfix("(4 + 2 * 5) / -(1 + 3 * 2)")) << "\n";
    cout << removeExtraWhiteSpace(ip.convertToPostfix("(4 + 2 * 5) /-(1 + 3 * 2)")) << "\n";
    cout << removeExtraWhiteSpace(ip.convertToPostfix("abc  = (1+ 2)*3 ")) << "\n";

    t.setInput("aE5");
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
