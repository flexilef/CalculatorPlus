#include "../include/PostfixEvaluatorTests.h"
#include <cassert>
#include <cmath>
#include <limits>

PostfixEvaluatorTests::PostfixEvaluatorTests()
{
    totalTestsRun = 0;
    totalTestsFailed = 0;
}

PostfixEvaluatorTests::~PostfixEvaluatorTests()
{
    //dtor
}

void PostfixEvaluatorTests::runTests()
{
    evaluate_unaryOperators_returnResult();
    evaluate_binaryOperators_returnResult();
    evaluate_basicFunctions_returnResult();
    evaluate_trigFunctions_returnResult();
    evaluate_assignmentOperator_checkAsignment();
    evaluate_constants_returnResult();
    evaluate_errors_returnError();

    std::cout << "PostfixEvaluatorTests: Tests run    : " << totalTestsRun << "\n";
    std::cout << "PostfixEvaluatorTests: Tests failed : " << totalTestsFailed << "\n";
}

void PostfixEvaluatorTests::evaluate_unaryOperators_returnResult()
{

}

void PostfixEvaluatorTests::evaluate_binaryOperators_returnResult()
{
    //addition
    checkResult("1 2 +", 3, "binary operator: addition: single digit");
    checkResult("12 34 +", 46, "binary operator: addition: multiple digit");
    checkResult("1.2 34.56 +", 35.76, "binary operator: addition: decimal point");
    checkResult("1 ~ 2 ~ +", -3, "binary operator: addition: negative");
    //checkResult("a bc +", 666, "binary operator: addition: variable");
    //checkResult("a ~ bc ~ +", 666, "binary operator: addition: negative variable");

    //subtraction
    checkResult("2 1 -", 1, "binary operator: subtraction: single digit: positive result");
    checkResult("1 2 -", -1, "binary operator: subtraction: single digit: negative result");
    checkResult("34 12 -", 22, "binary operator: subtraction: multiple digit: positive result");
    checkResult("12 34 -", -22, "binary operator: subtraction: multiple digit: positive result");
    checkResult("1.2 34.56 -", -33.36, "binary operator: subtraction: decimal point: negative result");
    checkResult("34.56 1.2 -", 33.36, "binary operator: subtraction: decimal point: positive result");
    //checkResult("a-bc", "a bc -", "binary operator: subtraction: variable");
    checkResult("1 ~ 2 ~ -", 1, "binary operator: subtraction: negative: positive result");
    checkResult("1 ~ 2 -", -3, "binary operator: subtraction: negative: positive result");
    //checkResult("-a--bc", "a ~ bc ~ -", "binary operator: subtraction: negative variable");
}

void PostfixEvaluatorTests::evaluate_basicFunctions_returnResult()
{

}

void PostfixEvaluatorTests::evaluate_trigFunctions_returnResult()
{

}

void PostfixEvaluatorTests::evaluate_assignmentOperator_checkAsignment()
{

}

void PostfixEvaluatorTests::evaluate_constants_returnResult()
{

}

void PostfixEvaluatorTests::evaluate_errors_returnError()
{

}

void PostfixEvaluatorTests::checkResult(const std::string &postfix, double answer, const std::string &error)
{
    totalTestsRun++;
    double result = evaluator.evaluate(postfix);

    if(!almostEqual(result, answer, 4))
    {
        totalTestsFailed++;
        std::cout << "Error found: " << error << "\n";
        std::cout << "postfix    : " << postfix << "\n";
        std::cout << "result     : " << result << "\n";
        std::cout << "answer     : " << answer << "\n";
    }
}

bool PostfixEvaluatorTests::almostEqual(double a, double b, int ulp)
{
    return std::abs(a - b) < std::numeric_limits<double>::epsilon()*std::abs(a + b)*ulp ||
            std::abs(a - b) < std::numeric_limits<double>::min();
}
