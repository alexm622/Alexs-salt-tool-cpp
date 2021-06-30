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

        const static std::string TEST_IN_ACCEPT_SRC;
        const static std::string TEST_LIST_IN_SRC;

        const static std::string TEST_IN_ACCEPT_DEST;
        const static std::string TEST_LIST_IN_DEST;

        static void Setup();
    protected:

    private:
        const static std::string TEMP_PATH;
};

#endif // TESTING_H
