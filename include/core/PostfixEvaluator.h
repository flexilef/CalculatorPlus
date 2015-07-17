#ifndef POSTFIXEVALUATOR_H
#define POSTFIXEVALUATOR_H

#include "MemoryBank.h"
#include "MathUtil.h"

class PostfixEvaluator
{
public:

    /** Default constructor */
    PostfixEvaluator();
    PostfixEvaluator(MemoryBank&);
    /** Default destructor */
    virtual ~PostfixEvaluator();

    double evaluatePostfix(const std::string&);
    void setAngleMode(MathUtil::AngleMode);

protected:

private:
    double evaluate(const std::string&);
    void assignment(std::string, double);

    MemoryBank& mBank;
    MathUtil mUtil;
    MathUtil::AngleMode angleMode;
};

#endif // POSTFIXEVALUATOR_H
