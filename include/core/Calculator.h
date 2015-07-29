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

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "MemoryBank.h"
#include "PostfixEvaluator.h"
#include "MathUtil.h"
#include "InfixToPostfixConverter.h"
#include "CalculatorUtil.h"

class Calculator
{
public:

    enum CalculatorState
    {
        DEFAULTSTATE = 0,
        ERRORSTATE,
    };

    /** Default constructor */
    Calculator();
    /** Default destructor */
    virtual ~Calculator();

    void calculate();
    void setCalculatorState(CalculatorState);
    CalculatorState getCalculatorState();
    std::string getErrorMessage();
    void setAngleMode(MathUtil::AngleMode);
    std::string getInput();
    void setInput(const std::string&);
    double getOutput();

    const std::vector<std::string>& getVariables();
    double getValueFromVariable(const std::string&);
    void clearMemory();

protected:
private:
    void checkInput();
    void checkAssignment();
    void checkInfix();
    void removeSpaces(std::string&);
    void applyAutoMultiplication();

    std::string input;
    double output;
    double lastAnswer;
    std::string errorMessage;
    CalculatorState calcState;
    MathUtil::AngleMode angleMode;

    MemoryBank mBank;
    InfixToPostfixConverter ipConverter;
    PostfixEvaluator pEvaluator;

    friend class CalculatorTests;
};

#endif // CALCULATOR_H
