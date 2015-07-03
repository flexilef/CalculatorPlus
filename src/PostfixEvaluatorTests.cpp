#include "../include/PostfixEvaluatorTests.h"
#include "../include/CalculatorUtil.h"
#include <cmath>
#include <iostream>

PostfixEvaluatorTests::PostfixEvaluatorTests() : evaluator(theBank)
{
    theBank.storeValueIntoVar("a", 1);
    theBank.storeValueIntoVar("b", 2);
    theBank.storeValueIntoVar("cd", 3);
    theBank.storeValueIntoVar("abc", 123);
    evaluator.setAngleMode(MathUtil::DEGREES);
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
    evaluate_assignmentOperator_checkAssignment();
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
    checkResult("a ~", -1,"unary operator: negation: variable");
    checkResult("abc ~", -123, "unary operator: negation: multiple variable");
    checkResult("abc ~ ~", 123, "unary operator: negation: double negative variable");

    //factorial
    checkResult("1 !", 1, "unary operator: factorial: single digit");
    checkResult("12 !", 4.790016e8, "unary operator: factorial: multiple digit");
    checkResult("1 ! ~", -1, "unary operator: factorial: negative");
    checkResult("1 ! !", 1, "unary operator: factorial: double factorial");
    checkResult("a !", 1, "unary operator: factorial: variable");
    checkResult("cd !", 6, "unary operator: factorial: multiple variable");
    checkResult("cd ! !", 720,"unary operator: factorial: double negative variable");

    //percent
    checkResult("1 %", .01, "unary operator: percent: single digit");
    checkResult("a %", .01, "unary operator: percent: variable");
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
    checkResult("a b +", 3, "binary operator: addition: variable");
    checkResult("a ~ b ~ +", -3, "binary operator: addition: negative variable");

    //subtraction
    checkResult("2 1 -", 1, "binary operator: subtraction: single digit: positive result");
    checkResult("1 2 -", -1, "binary operator: subtraction: single digit: negative result");
    checkResult("34 12 -", 22, "binary operator: subtraction: multiple digit: positive result");
    checkResult("12 34 -", -22, "binary operator: subtraction: multiple digit: positive result");
    checkResult("1.2 34.56 -", -33.36, "binary operator: subtraction: decimal point: negative result");
    checkResult("34.56 1.2 -", 33.36, "binary operator: subtraction: decimal point: positive result");
    checkResult("1 ~ 2 ~ -", 1, "binary operator: subtraction: negative: positive result");
    checkResult("1 ~ 2 -", -3, "binary operator: subtraction: negative: positive result");
    checkResult("a b -", -1, "binary operator: subtraction: variable");
    checkResult("a ~ b ~ -", 1, "binary operator: subtraction: negative variable");

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
    //checkResult("0 0 ^", 0, "binary operator: power: empty product"); //should equal NaN
    checkResult("1 0 ^", 1, "binary operator: power: zero exponent");
    checkResult("1 2 ^", 1, "binary operator: power: single digit");
    checkResult("12 34 ^", 4.92223524295202670404e36, "binary operator: power: multiple digit");
    checkResult("1.2 34.56 ^", 545.13474508838099979538, "binary operator: power: decimal point");
    checkResult("2 4 ^ ~", -16,"binary operator: power: negative base");
    checkResult("2 3 ~ ^",  0.125,"binary operator: power: negative exponent");
    checkResult("2 3 ~ ^ ~", -0.125,"binary operator: power: negative exponent and base");
    checkResult("2 3 ^ 4 ^", 4096,"binary operator: power: associativity");
    checkResult("a b ^", 1, "binary operator: power: variable");
    checkResult("a b ~ ^ ~", -1, "binary operator: power: negative variable");

    //E - Scientific Notation
    checkResult("1 2 E", 100, "binary operator: E: single digit");
    checkResult("12 34 E", 1.2e35, "binary operator: E: multiple digit");
    //checkResult("1.2 34.56 E", 0, "binary operator: E: decimal point");//make it return 1.2E35 floor(the value)
    checkResult("1 ~ 2 E", -100, "binary operator: E: negative coefficient");
    checkResult("1 2 ~ E", .01, "binary operator: E: negative exponent: small");
    checkResult("1 200 ~ E", 1e-200, "binary operator: E: negative exponent: large");
    checkResult("a 3 E", 1000, "binary operator: E: coefficient variable 2");
    checkResult("5 b E", 500, "binary operator: E: exponent variable");
    checkResult("a ~ 3 E", -1000, "binary operator: E: negative coefficient variable");
    checkResult("5 b ~ E", .05, "binary operator: E: negative exponent variable");
    checkResult("a b E", 100, "binary operator: E: exponent and coefficient variable");

    //mod
    checkResult("1 2 mod", 1, "binary operator: mod: single digit");
    checkResult("3 1 mod", 0, "binary operator: mod: zero");
    checkResult("34 12 mod", 10, "binary operator: mod: multiple digit");
    checkResult("34.56 1.2 mod", 0.96, "binary operator: mod: decimal point");
    checkResult("8 ~ 3 mod", -2, "binary operator: mod: negative");
}

void PostfixEvaluatorTests::evaluate_basicFunctions_returnResult()
{
    checkResult("12 log", 1.07918124604762482772, "basic functions: log");
    checkResult("12 ln", 2.48490664978800031023, "basic functions: ln");
    checkResult("81 sqrt", 9, "basic functions: sqrt");
    checkResult("2 exp", 7.38905609893065022723, "basic functions: exp");
    checkResult("5 ~ abs", 5, "basic functions: abs");
}

void PostfixEvaluatorTests::evaluate_trigFunctions_returnResult()
{
    checkResult("30 sin", 0.5, "basic functions: sin: degrees");
    checkResult("30 cos", 0.8660254, "basic functions: cos: degrees");
    checkResult("30 tan", 0.5773502, "basic functions: tan: degrees");
    checkResult(".5 asin", 30, "basic functions: asin: degrees");
    checkResult(".5 acos", 60, "basic functions: acos: degrees");
    checkResult(".5 atan", 26.565051, "basic functions: atan: degrees");
}

void PostfixEvaluatorTests::evaluate_assignmentOperator_checkAssignment()
{
    ///test 1
    MemoryBank mb;
    PostfixEvaluator pe(mb);

    totalTestsRun++;
    pe.evaluatePostfix("x 1 =");
    //std::cout << theBank.getValueFromVar("z");

    if(mb.getValueFromVar("x") != 1)
    {
        std::cout << "Error found: new var, number" << "\n";
        totalTestsFailed++;
    }
    mb.clearMemory();

    ///test 2
    totalTestsRun++;
    pe.evaluatePostfix("x 1 =");
    pe.evaluatePostfix("x 2 =");
    if(mb.getValueFromVar("x") != 2)
    {
        std::cout << "Error found: old var, number" << "\n";
        totalTestsFailed++;
    }
    mb.clearMemory();

    ///test 3
    totalTestsRun++;
    pe.evaluatePostfix("x 1 =");
    pe.evaluatePostfix("y x =");
    if(mb.getValueFromVar("y") != 1)
    {
        std::cout << "Error found: new var, old var" << "\n";
        totalTestsFailed++;
    }
    mb.clearMemory();

    ///test 4
    totalTestsRun++;
    pe.evaluatePostfix("x 1 =");
    pe.evaluatePostfix("y 2 =");
    pe.evaluatePostfix("y x =");
    if(mb.getValueFromVar("y") != 1)
    {
        std::cout << "Error found: old var, old var" << "\n";
        totalTestsFailed++;
    }
    mb.clearMemory();

    ///test 5: a=b=c not supported...
    /*totalTestsRun++;
    pe.evaluatePostfix("x 1 =");
    pe.evaluatePostfix("y 2 =");
    pe.evaluatePostfix("z 3 =");
    pe.evaluatePostfix("x y = z =");

    if(mb.getValueFromVar("x") != 3 ||
            mb.getValueFromVar("y") != 3 ||
            mb.getValueFromVar("z") != 3)
    {
        std::cout << "Error found: multiple variable reassignment: 3" << "\n";
        totalTestsFailed++;
    }
    mb.clearMemory();
    */
}

void PostfixEvaluatorTests::evaluate_constants_returnResult()
{
    checkResult("1", 1, "constants: single digit");
    checkResult("123", 123, "constants: multiple digit");
    checkResult("b", 2, "constants: single variable");
    checkResult("abc", 123, "constants: multiple variable");
}

void PostfixEvaluatorTests::evaluate_errors_returnError()
{
}

void PostfixEvaluatorTests::checkResult(const std::string &postfix, double answer, const std::string &error)
{
    totalTestsRun++;

    double result = evaluator.evaluatePostfix(postfix);

    if(!CalculatorUtil::almostEqual(result, answer, 9)) //4 works for most cases. 9 for mod operator decimal...
    {
        totalTestsFailed++;
        std::cout << "Error found: " << error << "\n";
        std::cout << "postfix    : " << postfix << "\n";
        std::cout << "result     : " << result << "\n";
        std::cout << "answer     : " << answer << "\n";
        std::cout << "\n";
    }
}
