#ifndef POSTFIXEVALUATORTESTS_H
#define POSTFIXEVALUATORTESTS_H

#include "../include/PostfixEvaluator.h"
#include "../include/UnitTest.h"

class PostfixEvaluatorTests : public UnitTest
{
    public:
        /** Default constructor */
        PostfixEvaluatorTests();
        /** Default destructor */
        virtual ~PostfixEvaluatorTests();
        void runTests();

    protected:

    private:
        MemoryBank theBank;
        MathUtil mUtil;
        PostfixEvaluator evaluator;

        //tests
        void evaluate_unaryOperators_returnResult();
        void evaluate_binaryOperators_returnResult();
        void evaluate_basicFunctions_returnResult();
        void evaluate_trigFunctions_returnResult();
        void evaluate_assignmentOperator_checkAssignment();
        void evaluate_constants_returnResult();
        void evaluate_errors_returnError();//overflow/underflow/div by zero etc...

        //helpers
        void checkResult(const std::string&, double, const std::string&);
        bool almostEqual(double, double, int);

};

#endif // POSTFIXEVALUATORTESTS_H
