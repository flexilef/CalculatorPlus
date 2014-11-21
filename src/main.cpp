#include <iostream>
#include "../include/InfixToPostfixConverter.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    InfixToPostfixConverter ip;

    cout << ip.convertToPostfix("1+2") << "\n";
    cout << ip.evaluate("1.5 2 *") << "\n";

    return 0;
}
