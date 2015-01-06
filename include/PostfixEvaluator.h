#ifndef POSTFIXEVALUATOR_H
#define POSTFIXEVALUATOR_H

#include <iostream>

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
        double result;
};

#endif // POSTFIXEVALUATOR_H
