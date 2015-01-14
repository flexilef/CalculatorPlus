#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "../include/MemoryBank.h"
#include "../include/PostfixEvaluator.h"

class Calculator
{
    public:
        /** Default constructor */
        Calculator();
        /** Default destructor */
        virtual ~Calculator();
    protected:
    private:
        double answer;
        MemoryBank memory;
};

#endif // CALCULATOR_H
