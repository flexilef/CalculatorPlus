#include <iostream>
#include "../include/InfixToPostfixConverter.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    InfixToPostfixConverter ip;

    cout << ip.convertToPostfix("(3*tan(6^2)+8*cos(60))/(3*4^0.5-1)") << "\n";
    //cout << ip.evaluate("1.5 2 *") << "\n";

    return 0;
}
