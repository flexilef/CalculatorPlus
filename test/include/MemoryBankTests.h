#ifndef MEMORYBANKTESTS_H
#define MEMORYBANKTESTS_H

#include "../../include/core/MemoryBank.h"
#include "../include/UnitTest.h"

class MemoryBankTests : public UnitTest
{
    public:
        /** Default constructor */
        MemoryBankTests();
        /** Default destructor */
        virtual ~MemoryBankTests();

        void runTests();

    protected:

    private:
        MemoryBank theBank;

        void MemoryBank_functions_canStoreAndRetrieveVariables();

        //helper
        std::map<std::string, double> createMap();
};

#endif // MEMORYBANKTESTS_H
