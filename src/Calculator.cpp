#include <iostream>

#include "../include/Calculator.h"
#include "../include/MathTokenizer.h"
#include "../include/CalculatorUtil.h"
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
        applyAutoMultiplication();
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
    MathTokenizer tk(input);
    Token currentToken;
    std::string strBeforeEqualSign;

    //assignment check
    while(tk.hasNext())
    {
        currentToken = tk.getNextToken();
        if(currentToken.getString() == "=")
            isAssignmentCheck = true;
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

    //infix check
    if(!CalculatorUtil::isInfix(input))
        throw CalculatorException("Syntax Error: not an infix expression");

    //variable follows numbers check
    tk.setInput(input);
    Token tokenFirst = tk.getNextToken();
    Token tokenSecond = tk.getNextToken();

    if(tokenFirst.tokenType == Token::VARIABLE ||
            tokenSecond.tokenType == Token::NUMBER)
    {
        throw CalculatorException("Syntax Error: variable cannot follow a number");
    }

    while(tk.hasNext())
    {
        if(tokenFirst.tokenType == Token::VARIABLE &&
                tokenSecond.tokenType == Token::NUMBER)
        {
            throw CalculatorException("Syntax Error: variable cannot follow a number");
        }

        tokenFirst = tokenSecond;
        tokenSecond = tk.getNextToken();
    }
}

void Calculator::applyAutoMultiplication()
{
    MathTokenizer tk(input);
    Token lastToken;
    Token currentToken = tk.getNextToken();
    std::vector<int> indicesToInsertMultiplication;
    int index = 0;
    int tokenIndexOfCurrentToken = 0;

    //find indices to insert multiplication sign
    while(tk.hasNext())
    {
        lastToken = currentToken;
        currentToken = tk.getNextToken();
        tokenIndexOfCurrentToken++;

        if(lastToken.tokenType == Token::NUMBER)
        {
            if(currentToken.tokenType == Token::VARIABLE ||
                    currentToken.tokenType == Token::FUNCTION)
            {
                index = tk.convertTokenIndexToInputIndex(tokenIndexOfCurrentToken);
                indicesToInsertMultiplication.push_back(index);
            }
            else if(currentToken.tokenType == Token::OPERATOR &&
                    currentToken.getString() == "(")
            {
                index = tk.convertTokenIndexToInputIndex(tokenIndexOfCurrentToken);
                indicesToInsertMultiplication.push_back(index);
            }
        }
    }

    //insert the multiplication signs
    int length = indicesToInsertMultiplication.size();
    for(int i = 0; i<length; i++)
    {
        index = indicesToInsertMultiplication[i];
        //+i offsets the added "*" sign to the input
        input.insert(index+i, "*");
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
