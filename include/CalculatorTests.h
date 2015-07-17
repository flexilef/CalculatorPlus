#ifndef CALCULATORTESTS_H
#define CALCULATORTESTS_H

#include "../include/Calculator.h"
#include "../include/UnitTest.h"

class CalculatorTests : public UnitTest
{
    public:
        /** Default constructor */
        CalculatorTests();
        /** Default destructor */
        virtual ~CalculatorTests();
        void runTests();

    protected:
    private:
        Calculator calc;

        //tests
        void applyAutoMultiplication_Number_Variable();
        void applyAutoMultiplication_Number_Function();
        void applyAutoMultiplication_Variable_Number();
        void applyAutoMultiplication_Variable_Function();
        void applyAutoMultiplication_Variable_Variable();
        void applyAutoMultiplication_Misc();

        //helpers
        void checkResult(const std::string&, const std::string&, const std::string&);
};

#endif // CALCULATORTESTS_H
