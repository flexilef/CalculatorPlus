#include "../include/MemoryBank.h"
#include <iostream>
#include <cassert>

MemoryBank::MemoryBank()
{
    //ctor
}

MemoryBank::~MemoryBank()
{
    //dtor
}

double MemoryBank::getValueFromVar(std::string variable)
{
    double value = 0;

    if(!variableToNumberMap.empty())
        value = variableToNumberMap[variable];

    return value;
}

bool MemoryBank::storeValueIntoVar(std::string variable, double value)
{
    bool isBadVarName = false;

    for(int i = 0; i < variable.length(); i++)
    {
        if(!isalpha(variable[i]))
            isBadVarName = true;
    }

    if(!isBadVarName)
    {
        variableToNumberMap[variable] = value;
    }
    else
        return false;

    return true;
    //std::cout << "error: MemoryBank: illegal variable name: \"" << variable << "\" \n";
}

bool MemoryBank::hasVariable(std::string variable)
{
    if(variableToNumberMap.count(variable) != 0)
        return true;

    return false;
}

void MemoryBank::clearMemory()
{
    variableToNumberMap.clear();
}
