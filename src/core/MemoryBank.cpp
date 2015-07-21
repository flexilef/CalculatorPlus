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
