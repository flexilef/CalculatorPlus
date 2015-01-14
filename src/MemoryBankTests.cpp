#include "../include/MemoryBankTests.h"

#include <iostream>

MemoryBankTests::MemoryBankTests()
{
    totalTestsRun = 0;
    totalTestsFailed = 0;
}

MemoryBankTests::~MemoryBankTests()
{
    //dtor
}

void MemoryBankTests::runTests()
{
    MemoryBank_functions_canStoreAndRetrieveVariables();

    std::cout << "MemoryBankTests: Tests run    : " << totalTestsRun << "\n";
    std::cout << "MemoryBankTests: Tests failed : " << totalTestsFailed << "\n";
}

void MemoryBankTests::MemoryBank_functions_canStoreAndRetrieveVariables()
{
    if(!theBank.storeValueIntoVar("var", 666))
    {
        totalTestsFailed++;

        std::cout << "error: storeValueIntoVar: cannot store legal var name \"var\"\n";
    }
    totalTestsRun++;

    if(theBank.storeValueIntoVar("abc1", 123))
    {
        totalTestsFailed++;

        std::cout << "error: storeValueIntoVar: stored illegal var name: \"abc1\"\n";
    }
    totalTestsRun++;

    if(theBank.storeValueIntoVar(" ", 999))
    {
        totalTestsFailed++;

        std::cout << "error: storeValueIntoVar: stored illegal var name: \" \"\n";
    }
    totalTestsRun++;

    if(theBank.getValueFromVar("var") != 666)
    {
        totalTestsFailed++;

        std::cout << "error: getValueFromVar: cannot get stored value: \"666\"\n";
    }
    totalTestsRun++;

}
