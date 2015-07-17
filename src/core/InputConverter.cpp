#include "../../include/core/InputConverter.h"

InputConverter::InputConverter()
{
    input = "";
}

InputConverter::InputConverter(const std::string& str)
{
    input = str;
}

InputConverter::~InputConverter()
{
    //dtor
}

std::string InputConverter::getInput()
{
    return input;
}

void InputConverter::setInput(const std::string& str)
{
    input = str;
}

std::string InputConverter::getOutput()
{
    return output;
}
