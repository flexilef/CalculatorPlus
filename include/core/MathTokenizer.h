/*
This file is part of Calculator+
Copyright (C) 2015 Felix Lee

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

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
