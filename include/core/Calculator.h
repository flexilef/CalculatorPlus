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
    void setCalculatorState(CalculatorState);
    CalculatorState getCalculatorState();
    std::string getErrorMessage();
    void setAngleMode(MathUtil::AngleMode);
    std::string getInput();
    void setInput(const std::string&);
    double getOutput();

    const std::vector<std::string>& getVariables();
    double getValueFromVariable(const std::string&);
    void clearMemory();

protected:
private:
    void checkInput();
    void checkAssignment();
    void checkInfix();
    void removeSpaces(std::string&);
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

    //friend class CalculatorTests;
};

#endif // CALCULATOR_H
