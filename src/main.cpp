#include <iostream>
#include "../include/InfixToPostfixConverter.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl << endl;

    InfixToPostfixConverter ip;

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

    cout << ip.convertToPostfix("2^3-9");

    //cout << ip.evaluate("1.5 2 *") << "\n";

    return 0;
}
