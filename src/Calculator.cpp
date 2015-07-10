#include <iostream>

#include "../include/Calculator.h"
#include "../include/MathTokenizer.h"
#include "../include/CalculatorException.h"
#include "../include/DomainException.h"
#include "../include/SyntaxException.h"
#include "../include/MathException.h"
#include "../include/DivideByZeroException.h"

Calculator::Calculator() : pEvaluator(mBank)
{
    output = 0;
    calcState = DEFAULTSTATE;
    angleMode = MathUtil::DEGREES;
    pEvaluator.setAngleMode(angleMode);
    mBank.storeValueIntoVar("PI", MathUtil::PI());
}

Calculator::~Calculator()
{
    //dtor
}

void Calculator::getUserInput()
{
    std::string str;
    std::cout << "Enter: ";
    std::getline(std::cin, str);
    setInput(str);
}

std::string Calculator::getInput()
{
    return input;
}

void Calculator::setInput(const std::string& str)
{
    input = str;
}

double Calculator::getOutput()
{
    return output;
}

void Calculator::calculate()
{
    double result = 0;

    try
    {
        checkInput();
        if(calcState == DEFAULTSTATE)
        {
            std::string postfix = ipConverter.convertToPostfix(input);
            result = pEvaluator.evaluatePostfix(postfix);
        }
    }
    catch(CalculatorException& e)
    {
        calcState = ERRORSTATE;
        errorMessage = e.what();
    }
    catch(...)
    {
        calcState = ERRORSTATE;
        errorMessage = "Unknown error";
    }

    output = result;
}

void Calculator::checkInput()
{
    bool isAssignmentCheck = false;
    bool isCommandCheck = false;

    MathTokenizer tk(input);
    Token currentToken;
    std::string strBeforeEqualSign;

    //get the kind of input
    while(tk.hasNext())
    {
        currentToken = tk.getNextToken();
        if(currentToken.getString() == "=")
            isAssignmentCheck = true;
        else if(currentToken.getString() == "?")
            isCommandCheck = true;
    }

    //reset
    tk.setInput(input);

    if(isAssignmentCheck)
    {
        //check assignment errors
        while(tk.hasNext() && currentToken.getString() != "=")
        {
            currentToken = tk.getNextToken();

            if(currentToken.getString() != "=")
                //get the string before the equal sign
                strBeforeEqualSign += currentToken.getString();
        }

        tk.setInput(strBeforeEqualSign);

        while(tk.hasNext())
        {
            if(tk.getNextToken().tokenType != Token::VARIABLE)
                throw CalculatorException("Syntax Error: invalid variable for assignment");

        }
    }

    if(isCommandCheck)
    {
        calcState = COMMANDSTATE;

        //check for command errors
        if(!isCommand(input))
            throw CalculatorException("Syntax Error: invalid command entered");
    }
}

void Calculator::setCalculatorState(CalculatorState state)
{
    calcState = state;
}
Calculator::CalculatorState Calculator::getCalculatorState()
{
    return calcState;
}

std::string Calculator::getErrorMessage()
{
    return errorMessage;
}

void Calculator::setAngleMode(MathUtil::AngleMode mode)
{
    angleMode = mode;
    pEvaluator.setAngleMode(mode);
}

bool Calculator::isCommand(const std::string &command)
{
    const int LENGTH = 10;
    std::string commands[LENGTH] = {"?radians", "?degrees", "?help", "?memory"};

    for(int i = 0; i < LENGTH; i++)
    {
        if(command == commands[i])
            return true;
    }

    return false;
}

void Calculator::runCommand(const std::string &command)
{
    if(isCommand(command))
    {
        if(command == "?radians")
            setAngleMode(MathUtil::RADIANS);
        else if(command == "?degrees")
            setAngleMode((MathUtil::DEGREES));
    }
}
