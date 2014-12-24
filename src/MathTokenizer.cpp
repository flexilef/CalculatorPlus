#include "../include/MathTokenizer.h"

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
    if(tokenIndex < tokens.size())
        return true;

    return false;
}

Token MathTokenizer::getNextToken()
{
    if(!tokens.empty() && tokenIndex < tokens.size())
    {
        Token nextToken = tokens[tokenIndex];

        //update tokenIndex
        tokenIndex++;

        return nextToken;
    }

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

        if(isNumber(currentCharacter))
        {
            numberStr+=currentCharacter;

        }
        else if(isalpha(input[index]))
        {
            variableStr+=currentCharacter;
            operatorStr+=currentCharacter;
            functionStr+=currentCharacter;

            //handle operators and functions before single operators are found
            if(isOperator(operatorStr))
            {
                if(!numberStr.empty())
                {
                    std::cout << "NUM1 ";
                    tokens.push_back(Token(numberStr, Token::NUMBER));
                    numberStr = "";
                }

                std::cout << "OP1 ";
                tokens.push_back(Token(operatorStr, Token::OPERATOR));

                variableStr = "";
                operatorStr = "";
                functionStr = "";
            }
            else if(isFunction(functionStr))
            {
                /**
                *Note that later on, if you want to implement auto multiplication such as
                *5cos(30) = 5*cos(30), just do...
                *if(!numberStr.empty())
                *{
                *   tokens.push_back(Token("*", Token::OPERATOR));
                *}
                */
                std::cout << "FUNC1 ";
                tokens.push_back(Token(functionStr, Token::FUNCTION));

                variableStr = "";
                operatorStr = "";
                functionStr = "";
            }
        }
        else if(isOperator(currentCharacter))
        {
            /**
            *Note that later on, if you want to implement variable names that accept both
            *alpha and numberical values, just check...
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
                std::cout << "VAR1 ";
                //found variable token
                tokens.push_back(Token(variableStr, Token::VARIABLE));
                //reset them
                variableStr = "";
                operatorStr = "";
                functionStr = "";
            }

            if(!numberStr.empty())
            {
                std::cout << "NUM2 ";
                tokens.push_back(Token(numberStr, Token::NUMBER));
                numberStr = "";
            }

            std::cout << "OP2 ";
            //now handle the single operators

            //handle special case of unary (this adds complexity to MathTokenizer,
            //but until a less messy way is found, tokenizer will worry about converting unaries AND tokenizing
            if(currentCharacter == "-")
            {
                if(index == 0)
                    isNegative = true;
                else if(isOperator(lastCharacter))
                    isNegative = true;
                else if(lastCharacter == "(")
                    isNegative = true;

                if(isNegative)
                {
                    //change to internal representation of unary negation: ~
                    currentCharacter = "~";
                    isNegative = false;
                }
            }
            tokens.push_back(Token(currentCharacter, Token::OPERATOR));
        }
    }

    //reached end of input. Handle the last token
    if(!variableStr.empty())
    {
        std::cout << "VAR2 ";
        //found variable token
        tokens.push_back(Token(variableStr, Token::VARIABLE));
        //reset them
        variableStr = "";
        operatorStr = "";
        functionStr = "";
    }

    if(!numberStr.empty())
    {
        std::cout << "NUM3 ";
        tokens.push_back(Token(numberStr, Token::NUMBER));
        numberStr = "";
    }

    std::cout << "\n";
}

void MathTokenizer::setInput(const std::string &str)
{
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

bool MathTokenizer::isNumber(const std::string &str)
{
    if(isdigit(str[0]) || str == ".")
        return true;

    return false;
}

bool MathTokenizer::isOperator(const std::string &str)
{
    std::string operators[20] = {"+", "-", "~", "*", "/", "^", "(", ")"};

    if(!str.empty())
    {
        for(int i = 0; i < 20; i++)
        {
            if(str == operators[i])
                return true;
        }
    }

    return false;
}

bool MathTokenizer::isFunction(const std::string &str)
{
    std::string functions[10] = {"sin", "cos", "tan", "ln"};

    if(!str.empty())
    {
        for(int i = 0; i < 10; i++)
        {
            if(functions[i] == str)
                return true;
        }
    }

    return false;
}
