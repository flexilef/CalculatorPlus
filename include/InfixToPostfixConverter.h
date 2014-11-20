#ifndef INFIXTOPOSTFIXCONVERTER_H
#define INFIXTOPOSTFIXCONVERTER_H

#include "InputConverter.h"

class InfixToPostfixConverter : public InputConverter
{
    public:
        /** Default constructor */
        InfixToPostfixConverter();

        /** Default destructor */
        virtual ~InfixToPostfixConverter();

        void convert();

    //protected:

    //private:

        int getPrecedence(char);

        bool isVariable(char);
};

#endif // INFIXTOPOSTFIXCONVERTER_H
