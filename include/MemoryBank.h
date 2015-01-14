#ifndef MEMORYBANK_H
#define MEMORYBANK_H

#include <string>
#include <map>

class MemoryBank
{
    public:
        /** Default constructor */
        MemoryBank();
        /** Default destructor */
        virtual ~MemoryBank();

        double getValueFromVar(std::string);
        bool storeValueIntoVar(std::string, double);
        void clearMemory();
    protected:
    private:
        std::map<std::string, double> variableToNumberMap;
};

#endif // MEMORYBANK_H
