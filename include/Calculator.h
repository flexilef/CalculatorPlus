#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "../include/MemoryBank.h"
#include "../include/PostfixEvaluator.h"
#include "../include/MathUtil.h"

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
        std::string errorMessage;
        MemoryBank memory;
};

#endif // CALCULATOR_H
