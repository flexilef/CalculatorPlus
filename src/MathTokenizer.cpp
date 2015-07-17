#include <iostream>

#include "../include/MathTokenizer.h"
#include "../include/CalculatorException.h"
#include "CalculatorUtil.cpp"

MathTokenizer::MathTokenizer()
{
    input = "";
    tokenIndex = 0;
}

MathTokenizer::MathTokenizer(const std::string &str)
{
    input = str;
    tokenIndex = 0;
    tokenize();
}

MathTokenizer::~MathTokenizer()
{
    //dtor
}

bool MathTokenizer::hasNext()
{
    if(!tokens.empty() && tokenIndex < tokens.size())
        return true;

    return false;
}

Token MathTokenizer::getNextToken()
{
    if(hasNext())
    {
        Token nextToken = tokens[tokenIndex];
        tokenIndex++;

        return nextToken;
    }

    //might want to change this later to throw an exception
    return Token("", Token::UNUSED);
}

void MathTokenizer::tokenize()
{
    std::string numberStr;
    std::string variableStr;
    std::string operatorStr;
    std::string functionStr;
    std::string currentCharacter;
    int length = input.length();

    for(int index = 0; index < length; index++)
    {
        currentCharacter = input.substr(index, 1);

        if(CalculatorUtil::isNumber(currentCharacter))
        {
            numberStr+=currentCharacter;
        }
        else if(isalpha(input[index]))// && !CalculatorUtil::isOperator(currentCharacter))
        {
            if(!numberStr.empty())
            {
                //std::cout << "NUM1 ";
                tokens.push_back(Token(numberStr, Token::NUMBER));

                numberStr = "";
            }

            //could be either one of these three
            operatorStr+=currentCharacter;
            functionStr+=currentCharacter;
            variableStr+=currentCharacter;

            //handle multiple-charactered operators and functions
            if(CalculatorUtil::isOperator(operatorStr))
            {
                //std::cout << "OP1 ";
                tokens.push_back(Token(operatorStr, Token::OPERATOR));

                //reset them
                variableStr = "";
                operatorStr = "";
                functionStr = "";
            }
            else if(CalculatorUtil::isFunction(functionStr))
            {
                //std::cout << "FUNC1 ";
                tokens.push_back(Token(functionStr, Token::FUNCTION));

                variableStr = "";
                operatorStr = "";
                functionStr = "";
            }
        }
        else if(CalculatorUtil::isOperator(currentCharacter))
        {
            //handle any tokens found before the single operator is found
            if(!variableStr.empty())
            {
                //std::cout << "VAR1 ";
                tokens.push_back(Token(variableStr, Token::VARIABLE));

                variableStr = "";
                operatorStr = "";
                functionStr = "";
            }

            if(!numberStr.empty())
            {
                //std::cout << "NUM2 ";
                tokens.push_back(Token(numberStr, Token::NUMBER));

                numberStr = "";
            }

            //std::cout << "OP2 ";
            tokens.push_back(Token(currentCharacter, Token::OPERATOR));
        }
        //handle white spaces between operands
        else if(currentCharacter == " ")
        {
            if(!numberStr.empty())
            {
                //std::cout << "NUM3 ";
                tokens.push_back(Token(numberStr, Token::NUMBER));

                numberStr = "";
            }

            if(!variableStr.empty())
            {
                //std::cout << "VAR2 ";
                tokens.push_back(Token(variableStr, Token::VARIABLE));
                variableStr = "";
                operatorStr = "";
                functionStr = "";
            }
        }
        else
            throw CalculatorException("Syntax Error: invalid character: " + currentCharacter);
    }

    //reached end of input. Handle the last token
    if(!variableStr.empty())
    {
        //std::cout << "VAR2 ";
        tokens.push_back(Token(variableStr, Token::VARIABLE));

        variableStr = "";
        operatorStr = "";
        functionStr = "";
    }

    if(!numberStr.empty())
    {
        //std::cout << "NUM4 ";
        tokens.push_back(Token(numberStr, Token::NUMBER));

        numberStr = "";
    }
}

int MathTokenizer::convertTokenIndexToInputIndex(int tIndex)
{
    int inputIndex = 0;

    for(int i = 0; i<=tIndex; i++)
    {
        inputIndex+=tokens[i].getString().length();
    }

    if(tIndex == 0)
        inputIndex = 0;
    else
        //get the index at the beginning of the token string
        inputIndex-=tokens[tIndex].getString().length();

    return inputIndex;
}

void MathTokenizer::setInput(const std::string &str)
{
    clear();
    input = str;
    tokenize();
}

void MathTokenizer::clear()
{
    input = "";
    tokenIndex = 0;
    tokens.clear();
}

void MathTokenizer::dumpTokens()
{
    int length = tokens.size();

    std::cout << "TokenLength: " << length << "\n";
    std::cout << "Tokens: \n";

    for(int i = 0; i < length; i++)
    {
        std::cout << tokens[i].getString() << ":";
        std::cout << tokens[i].tokenType << " ";
    }
}
