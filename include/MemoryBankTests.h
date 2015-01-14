#ifndef MEMORYBANKTESTS_H
#define MEMORYBANKTESTS_H

#include "../include/MemoryBank.h"

class MemoryBankTests
{
    public:
        /** Default constructor */
        MemoryBankTests();
        /** Default destructor */
        virtual ~MemoryBankTests();

        void runTests();
    protected:
    private:
        int totalTestsRun;
        int totalTestsFailed;
        MemoryBank theBank;

        void MemoryBank_functions_canStoreAndRetrieveVariables();

        //helper
        std::map<std::string, double> createMap();
};

#endif // MEMORYBANKTESTS_H
