#include "../include/MathTokenizer.h"
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

    //might want to change this later
    return Token("", Token::UNUSED);
}

void MathTokenizer::tokenize()
{
    std::string numberStr;
    std::string variableStr;
    std::string operatorStr;
    std::string functionStr;
    int length = input.length();
    bool isNegative = false;

    for(int index = 0; index < length; index++)
    {
        std::string currentCharacter = input.substr(index, 1);
        std::string lastCharacter;

        if(index > 0 && input.substr(index - 1, 1) != " ")
        {
            lastCharacter = input.substr(index - 1, 1);
        }

        //begin tokenizing...
        if(CalculatorUtil::isNumber(currentCharacter))
        {
            numberStr+=currentCharacter;
        }
        else if(isalpha(input[index]))// && !CalculatorUtil::isOperator(currentCharacter))
        {
            //could be either one of these three
            operatorStr+=currentCharacter;
            functionStr+=currentCharacter;
            variableStr+=currentCharacter;

            //handle operators and functions before single operators are found
            if(CalculatorUtil::isOperator(operatorStr))
            {
                if(!numberStr.empty())
                {
                    //std::cout << "NUM1 ";
                    tokens.push_back(Token(numberStr, Token::NUMBER));
                    numberStr = "";
                }

                //std::cout << "OP1 ";
                tokens.push_back(Token(operatorStr, Token::OPERATOR));

                variableStr = "";
                operatorStr = "";
                functionStr = "";
            }
            else if(CalculatorUtil::isFunction(functionStr))
            {

                //Note that later on, if you want to implement auto multiplication such as
                //5cos(30) = 5*cos(30), just do...
                //if(!numberStr.empty())
                //{
                //   tokens.push_back(Token("*", Token::OPERATOR));
                //}

                //std::cout << "FUNC1 ";
                tokens.push_back(Token(functionStr, Token::FUNCTION));

                variableStr = "";
                operatorStr = "";
                functionStr = "";
            }
        }
        else if(CalculatorUtil::isOperator(currentCharacter))
        {
            /**
            *Note that later on, if you want to implement variable names that accept both
            *alpha and numerical values, just check...
            *if(!numberStr.empty() && !variableStr.empty())
            *{
            *   tokens.push_back(Token(variableStr, Token::VARIABLE));
            *}
            *take note however that the if statement that checks if currentChar is a number
            *must also do...
            *variableStr+=currentCharacter;
            */

            //handle any tokens found before the single operator is found
            if(!variableStr.empty())
            {
                //std::cout << "VAR1 ";
                //found variable token
                tokens.push_back(Token(variableStr, Token::VARIABLE));
                //reset them
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
                //found variable token
                tokens.push_back(Token(variableStr, Token::VARIABLE));
                //reset them
                variableStr = "";
                operatorStr = "";
                functionStr = "";
            }
        }
    }

    //reached end of input. Handle the last token
    if(!variableStr.empty())
    {
        //std::cout << "VAR2 ";
        //found variable token
        tokens.push_back(Token(variableStr, Token::VARIABLE));
        //reset them
        variableStr = "";
        operatorStr = "";
        functionStr = "";
    }

    if(!numberStr.empty())
    {
        //std::cout << "NUM3 ";
        tokens.push_back(Token(numberStr, Token::NUMBER));
        numberStr = "";
    }
}

void MathTokenizer::setInput(const std::string &str)
{
    clear();    //don't forget to reset everything
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
