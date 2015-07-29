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

#ifndef POSTFIXEVALUATOR_H
#define POSTFIXEVALUATOR_H

#include "MemoryBank.h"
#include "MathUtil.h"

class PostfixEvaluator
{
public:

    /** Default constructor */
    PostfixEvaluator();
    PostfixEvaluator(MemoryBank&);
    /** Default destructor */
    virtual ~PostfixEvaluator();

    double evaluatePostfix(const std::string&);
    void setAngleMode(MathUtil::AngleMode);

protected:

private:
    double evaluate(const std::string&);
    void assignment(std::string, double);

    MemoryBank& mBank;
    MathUtil mUtil;
    MathUtil::AngleMode angleMode;
};

#endif // POSTFIXEVALUATOR_H
