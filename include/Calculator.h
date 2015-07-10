#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "../include/MemoryBank.h"
#include "../include/PostfixEvaluator.h"
#include "../include/MathUtil.h"
#include "../include/InfixToPostfixConverter.h"

class Calculator
{
public:

    enum CalculatorState
    {
        DEFAULTSTATE = 0,
        COMMANDSTATE,
        ERRORSTATE,
    };

    /** Default constructor */
    Calculator();
    /** Default destructor */
    virtual ~Calculator();

    void calculate();
    void getUserInput();
    std::string getInput();
    void setInput(const std::string&);
    double getOutput();
    std::string getErrorMessage();
    void setCalculatorState(CalculatorState);
    CalculatorState getCalculatorState();
    void setAngleMode(MathUtil::AngleMode);
    void runCommand(const std::string&);

protected:
private:
    void checkInput();
    bool isCommand(const std::string&);

    std::string input;
    double output;

    std::string errorMessage;
    CalculatorState calcState;
    MathUtil::AngleMode angleMode;

    MemoryBank mBank;
    InfixToPostfixConverter ipConverter;
    PostfixEvaluator pEvaluator;
};

#endif // CALCULATOR_H
