#ifndef POSTFIXEVALUATOR_H
#define POSTFIXEVALUATOR_H

#include <iostream>
#include "../include/MathTokenizer.h"

class PostfixEvaluator
{
    public:
        /** Default constructor */
        PostfixEvaluator();
        /** Default destructor */
        virtual ~PostfixEvaluator();

        double evaluate(const std::string&);

    protected:

    private:
        MathTokenizer tokenizer;
        double result;
};

#endif // POSTFIXEVALUATOR_H
