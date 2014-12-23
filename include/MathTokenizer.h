#ifndef MATHTOKENIZER_H
#define MATHTOKENIZER_H

#include <vector>
#include "Token.h"

class MathTokenizer
{
public:
    /** Default constructor */
    MathTokenizer();

    MathTokenizer(std::string);

    /** Default destructor */
    virtual ~MathTokenizer();

    bool hasNext();
    Token getNextToken();
    void tokenize();
    void dumpTokens();

protected:

private:

    std::string input;
    std::string output;
    std::vector<Token> tokens;
    int tokenIndex;

    bool isNumber(const std::string);
    bool isOperator(const std::string);
    bool isFunction(const std::string);
};

#endif // MATHTOKENIZER_H
