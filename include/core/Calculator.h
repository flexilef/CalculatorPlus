#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "MemoryBank.h"
#include "PostfixEvaluator.h"
#include "MathUtil.h"
#include "InfixToPostfixConverter.h"
#include "CalculatorUtil.h"

class Calculator
{
public:

    enum CalculatorState
    {
        DEFAULTSTATE = 0,
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

protected:
private:
    void checkInput();
    void checkAssignment();
    void checkInfix();
    void applyAutoMultiplication();

    std::string input;
    double output;
    double lastAnswer;
    std::string errorMessage;
    CalculatorState calcState;
    MathUtil::AngleMode angleMode;

    MemoryBank mBank;
    InfixToPostfixConverter ipConverter;
    PostfixEvaluator pEvaluator;

    friend class CalculatorTests;
};

#endif // CALCULATOR_H
