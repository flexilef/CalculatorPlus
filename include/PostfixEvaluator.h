#ifndef POSTFIXEVALUATOR_H
#define POSTFIXEVALUATOR_H

#include "../include/MathTokenizer.h"
#include "../include/MemoryBank.h"

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
        MathTokenizer tokenizer;
        MemoryBank& theBank;
        double evaluate(const std::string&);

};

#endif // POSTFIXEVALUATOR_H
