#include <iostream>

#include "../../include/core/Calculator.h"
#include "../../include/core/MathTokenizer.h"

#include "../../include/core/CalculatorException.h"
#include "../../include/core/DomainException.h"
#include "../../include/core/SyntaxException.h"
#include "../../include/core/MathException.h"
#include "../../include/core/DivideByZeroException.h"

Calculator::Calculator() : pEvaluator(mBank)
{
    output = 0;
    lastAnswer = 0;
    calcState = DEFAULTSTATE;
    angleMode = MathUtil::DEGREES;
    pEvaluator.setAngleMode(angleMode);
    mBank.storeValueIntoVar("PI", MathUtil::PI());
    mBank.storeValueIntoVar("ans", lastAnswer);
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

void Calculator::calculate()
{
    try
    {
        applyAutoMultiplication();
        checkInput();

        std::string postfix = ipConverter.convertToPostfix(input);
        output = pEvaluator.evaluatePostfix(postfix);
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

    lastAnswer = output;
    mBank.storeValueIntoVar("ans", lastAnswer);
}

void Calculator::checkInput()
{
    checkAssignment();
    checkInfix();
}

void Calculator::checkInfix()
{
    if(!CalculatorUtil::isInfix(input))
        throw CalculatorException("Syntax Error: '" + input + "' is not an infix expression");
}

void Calculator::checkAssignment()
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
            currentToken = tk.getNextToken();
            if(currentToken.tokenType != Token::VARIABLE)
                throw CalculatorException("Syntax Error: illegal variable name");
            else if(currentToken.tokenType == Token::VARIABLE)
            {
                if(currentToken.getString() == "PI" ||
                        currentToken.getString() == "ans")
                    throw CalculatorException("Syntax Error: cannot reassign: '" + currentToken.getString() + "'");
            }
        }
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
        else if(lastToken.tokenType == Token::VARIABLE)
        {
            if(currentToken.tokenType == Token::NUMBER ||
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
        else if(lastToken.tokenType == Token::OPERATOR &&
                lastToken.getString() == ")")
        {
            if(currentToken.tokenType == Token::OPERATOR &&
                    currentToken.getString() == "(")
            {
                index = tk.convertTokenIndexToInputIndex(tokenIndexOfCurrentToken);
                indicesToInsertMultiplication.push_back(index);
            }
            else if(currentToken.tokenType == Token::FUNCTION)
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
