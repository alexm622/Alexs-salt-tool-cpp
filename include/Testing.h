#ifndef TESTING_H
#define TESTING_H

#include <string>

class Testing
{
    public:
        Testing();
        virtual ~Testing();

        static bool isTestMode;

        const static std::string TEST_PATH;
        const static std::string TEST_IN_ACCEPT;
        const static std::string TEST_LIST_IN;

        static void Setup();
    protected:

    private:
};

#endif // TESTING_H
