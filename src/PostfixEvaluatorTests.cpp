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
    //unary negation
    checkResult("1 ~", -1, "unary operator: negation: single digit");
    checkResult("12 ~", -12, "unary operator: negation: multiple digit");
    checkResult("1.2 ~", -1.2, "unary operator: negation: decimal point");
    checkResult("1 ~ ~", 1, "unary operator: negation: double negative");
    //checkResult("a ~","unary operator: negation: variable");
    //checkResult("-abc", "abc ~","unary operator: negation: multiple variable");
    //checkResult("--abc", "abc ~ ~","unary operator: negation: double negative variable");

    //factorial
    checkResult("1 !", 1, "unary operator: factorial: single digit");
    checkResult("12 !", 4.790016e8, "unary operator: factorial: multiple digit");
    checkResult("1 ! ~", -1, "unary operator: factorial: negative");
    checkResult("1 ! !", 1, "unary operator: factorial: double factorial");
    //checkResult("a !","unary operator: factorial: variable");
    //checkResult("abc!", "abc !","unary operator: factorial: multiple variable");
    //checkResult("abc!!", "abc ! !","unary operator: factorial: double negative variable");
    //checkResult("1 ~ !", -1, "unary operator: factorial: negative");  //error
}

void PostfixEvaluatorTests::evaluate_binaryOperators_returnResult()
{

    //addition
    checkResult("0 0 +", 0, "binary operator: addition: zero");
    checkResult("1 0 +", 1, "binary operator: addition: identity");
    checkResult("1 ~ 1 +", 0, "binary operator: addition: inverse");
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
    checkResult("1 ~ 2 ~ -", 1, "binary operator: subtraction: negative: positive result");
    checkResult("1 ~ 2 -", -3, "binary operator: subtraction: negative: positive result");
    //checkResult("a-bc", "a bc -", "binary operator: subtraction: variable");
    //checkResult("-a--bc", "a ~ bc ~ -", "binary operator: subtraction: negative variable");

    //multiplication
    checkResult("1 2 *", 2, "binary operator: multiplication: single digit");
    checkResult("12 34 *", 408, "binary operator: multiplication: multiple digit");
    checkResult("1.2 34.56 *", 41.472, "binary operator: multiplication: decimal point");
    checkResult("1 ~ 2 ~ *", 2, "binary operator: multiplication: negative: positive result");
    checkResult("1 ~ 2 *", -2, "binary operator: multiplication: negative: negative result");

    //division
    checkResult("1 2 /", .5, "binary operator: division: single digit");
    checkResult("12 34 /", 0.35294117647058823529, "binary operator: division: multiple digit");
    checkResult("1.2 34.56 /", 0.03472222222222222222, "binary operator: division: decimal point");
    checkResult("1 ~ 2 ~ /", .5, "binary operator: division: negative: positive result");
    checkResult("1 ~ 2 /", -.5, "binary operator: division: negative: negative result");

    //power
    checkResult("0 0 ^", 0, "binary operator: power: empty product"); //should equal NaN
    checkResult("1 0 ^", 1, "binary operator: power: zero exponent");
    checkResult("1 2 ^", 1, "binary operator: power: single digit");
    checkResult("12 34 ^", 4.92223524295202670404e36, "binary operator: power: multiple digit");
    checkResult("1.2 34.56 ^", 545.13474508838099979538, "binary operator: power: decimal point");
    checkResult("2 4 ^ ~", -16,"binary operator: power: negative base");
    checkResult("2 3 ~ ^",  0.125,"binary operator: power: negative exponent");
    checkResult("2 3 ~ ^ ~", -0.125,"binary operator: power: negative exponent and base");
    checkResult("2 3 ^ 4 ^", 4096,"binary operator: power: associativity");
    //checkResult("a bc ^", "binary operator: power: variable");
    //checkResult("a bc ~ ^ ~", "binary operator: power: negative variable");

    //E - Scientific Notation
    checkResult("1 2 E", 100, "binary operator: E: single digit");
    checkResult("12 34 E", 1.2e35, "binary operator: E: multiple digit");
    checkResult("1.2 34.56 E", 0, "binary operator: E: decimal point");//no such thing remove?
    checkResult("1 ~ 2 E", -100, "binary operator: E: negative coefficient");
    checkResult("1 2 ~ E", .01, "binary operator: E: negative exponent: small");
    checkResult("1 200 ~ E", 1e-200, "binary operator: E: negative exponent: large");
    //checkResult("a 5 E", , "binary operator: E: coefficient variable 2");
    //checkResult("5 a E", , "binary operator: E: exponent variable");
    //checkResult("a ~ 5 E", , "binary operator: E: negative coefficient variable");
    //checkResult("5 a ~ E", , "binary operator: E: negative exponent variable");
    //checkResult("a b E", , "binary operator: E: exponent and coefficient variable");

    //mod
    checkResult("1 2 mod", 1, "binary operator: mod: single digit");
    checkResult("3 1 mod", 0, "binary operator: mod: zero");
    checkResult("34 12 mod", 10, "binary operator: mod: multiple digit");
    checkResult("34.56 1.2 mod", 0.96, "binary operator: mod: decimal point");
    checkResult("8 ~ 3 mod", -2, "binary operator: mod: negative");
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
    double result = evaluator.evaluatePostfix(postfix);

    if(!almostEqual(result, answer, 9)) //4 works for most cases. 9 for mod operator decimal...
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
