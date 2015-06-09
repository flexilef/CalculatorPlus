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

        double calculate();
        std::string getErrorMessage();
        void setErrorState(bool);
        bool getErrorState();
        std::string getInput();
        void setInput(const std::string&);
        void getUserInput();
        double getOutput();

    protected:
    private:
        double output;
        std::string input;
        std::string errorMessage;
        bool errorState;

        MemoryBank mBank;
        InfixToPostfixConverter ipConverter;
        PostfixEvaluator pEvaluator;
};

#endif // CALCULATOR_H
