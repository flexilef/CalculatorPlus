#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "../include/MemoryBank.h"
#include "../include/PostfixEvaluator.h"
#include "../include/InfixToPostfixConverter.h"

class Calculator
{
    public:
        /** Default constructor */
        Calculator();
        /** Default destructor */
        virtual ~Calculator();

        void setInput(const std::string&);
        std::string getInput();
        void getUserInput();
        double getOutput();
        double calculate();

    protected:
    private:
        double output;
        std::string input;

        MemoryBank mBank;
        InfixToPostfixConverter ipConverter;
        PostfixEvaluator pEvaluator;
};

#endif // CALCULATOR_H
