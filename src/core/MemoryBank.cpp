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

#include <iostream>
#include <algorithm>

#include "../../include/core/MemoryBank.h"

MemoryBank::MemoryBank()
{
    //ctor
}

MemoryBank::~MemoryBank()
{
    //dtor
}

double MemoryBank::getValueFromVar(const std::string &variable)
{
    double value = 0;

    if(!variableToNumberMap.empty())
        value = variableToNumberMap[variable];

    return value;
}

bool MemoryBank::storeValueIntoVar(const std::string &variable, double value)
{
    if(variable.empty() ||
            variable.find_first_not_of(' ') == std::string::npos)
        return false;

    variableToNumberMap[variable] = value;

    if(std::find(variables.begin(), variables.end(), variable) == variables.end())
        variables.push_back(variable);

    return true;
}

bool MemoryBank::hasVariable(const std::string &variable)
{
    if(variableToNumberMap.count(variable) != 0)
        return true;

    return false;
}

const std::vector<std::string>& MemoryBank::getListOfVariables()
{
    return variables;
}

void MemoryBank::removeVariable(const std::string &var)
{
    variableToNumberMap.erase(var);
    variables.erase(std::remove(variables.begin(), variables.end(), var), variables.end());
}

bool MemoryBank::isEmpty()
{
    return variables.empty();
}

void MemoryBank::clearMemory()
{
    variableToNumberMap.clear();
    variables.clear();
}
