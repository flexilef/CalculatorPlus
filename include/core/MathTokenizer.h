#ifndef MATHTOKENIZER_H
#define MATHTOKENIZER_H

#include <vector>

#include "Token.h"

class MathTokenizer
{
public:
    /** Default constructor */
    MathTokenizer();
    MathTokenizer(const std::string&);
    /** Default destructor */
    virtual ~MathTokenizer();

    bool hasNext();
    Token getNextToken();
    void setInput(const std::string&);
    void clear();
    void dumpTokens();
    int convertTokenIndexToInputIndex(int);

protected:

private:

    std::string input;
    std::vector<Token> tokens;
    int tokenIndex;

    void tokenize();
};

#endif // MATHTOKENIZER_H
