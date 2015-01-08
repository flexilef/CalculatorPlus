#ifndef POSTFIXEVALUATORTESTS_H
#define POSTFIXEVALUATORTESTS_H

#include "../include/PostfixEvaluator.h"

class PostfixEvaluatorTests
{
    public:
        /** Default constructor */
        PostfixEvaluatorTests();
        /** Default destructor */
        virtual ~PostfixEvaluatorTests();

        void runTests();
    protected:
    private:
        PostfixEvaluator evaluator;
        int totalTestsRun;
        int totalTestsFailed;

        //tests
        void evaluate_unaryOperators_returnResult();
        void evaluate_binaryOperators_returnResult();
        void evaluate_basicFunctions_returnResult();
        void evaluate_trigFunctions_returnResult();
        void evaluate_assignmentOperator_checkAsignment();
        void evaluate_constants_returnResult();
        void evaluate_errors_returnError();//overflow/underflow/div by zero etc...

        //helpers
        void checkResult(const std::string&, double, const std::string&);
        bool almostEqual(double, double, int);

};

#endif // POSTFIXEVALUATORTESTS_H
