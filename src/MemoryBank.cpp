#include "../include/MemoryBank.h"
#include <iostream>

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
    if(variable.empty() ||
       variable.find_first_not_of(' ') == std::string::npos)
        return false;

    variableToNumberMap[variable] = value;

    return true;
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
