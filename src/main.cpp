#include <iostream>
#include "../include/InfixToPostfixConverter.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    InfixToPostfixConverter ip;

    cout << "Initial input: \n" << ip.getInput();
    cout << "Initial output: \n" << ip.getOutput();
    cout << "Precedence Test (*): " << ip.getPrecedence('*') << "\n";
    cout << "isVariable Test (a): " << ip.isVariable('a') << "\n";
    cout << "isVariable Test (3): " << ip.isVariable('3') << "\n";
    cout << "isVariable Test (.): " << ip.isVariable('.') << "\n";
    cout << "isVariable Test (#): " << ip.isVariable('#') << "\n";
    cout << "Input Test (12+3*2.5): \n";
    ip.setInput("12+3*2.5");
    cout << "input (12+3*2.5): " << ip.getInput() << "\n";
    cout << "Output: " << ip.getOutput() << "\n";
    cout << "Convert Test (12+13*2.5): \n";
    ip.convert();
    cout << "Output: " << ip.getOutput() << "\n";

    return 0;
}
