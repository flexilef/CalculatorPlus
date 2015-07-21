#ifndef MEMORYBANK_H
#define MEMORYBANK_H

#include <string>
#include <vector>
#include <map>

class MemoryBank
{
    public:
        /** Default constructor */
        MemoryBank();
        /** Default destructor */
        virtual ~MemoryBank();

        double getValueFromVar(const std::string&);
        bool storeValueIntoVar(const std::string&, double);
        const std::vector<std::string>& getListOfVariables();
        bool hasVariable(const std::string&);
        bool isEmpty();
        void clearMemory();
        void removeVariable(const std::string&);
    protected:
    private:
        std::map<std::string, double> variableToNumberMap;
        std::vector<std::string> variables;
};

#endif // MEMORYBANK_H
