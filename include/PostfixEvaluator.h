#ifndef POSTFIXEVALUATOR_H
#define POSTFIXEVALUATOR_H

#include "../include/MemoryBank.h"
#include "../include/MathUtil.h"

class PostfixEvaluator
{
public:
    /** Default constructor */
    PostfixEvaluator();
    PostfixEvaluator(MemoryBank&);
    /** Default destructor */
    virtual ~PostfixEvaluator();

    double evaluatePostfix(const std::string&);

protected:

private:
    MemoryBank& mBank;
    MathUtil mUtil;
    double evaluate(const std::string&);
    void assignment(std::string, double);
};

#endif // POSTFIXEVALUATOR_H
