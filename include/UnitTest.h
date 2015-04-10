#ifndef UNITTEST_H
#define UNITTEST_H


class UnitTest
{
    public:
        /** Default constructor */
        UnitTest();
        /** Default destructor */
        virtual ~UnitTest();

        virtual void runTests() = 0;

    protected:
        int totalTestsRun;
        int totalTestsFailed;
};

#endif // UNITTEST_H
