#ifndef INPUTCONVERTER_H
#define INPUTCONVERTER_H

#include <iostream>


class InputConverter
{
    public:
        /** Default constructor */
        InputConverter();

        InputConverter(const std::string&);

        /** Default destructor */
        virtual ~InputConverter();

        virtual void convert() = 0;

        std::string getInput();

        void setInput(const std::string&);

        std::string getOutput();

        void setOutput(const std::string&);

    protected:

        std::string input;

        std::string output;

    private:
};

#endif // INPUTCONVERTER_H
