#ifndef TESTING_H
#define TESTING_H

#include <string>

class Testing
{
    public:
        Testing();
        virtual ~Testing();

        static bool isTestMode;

        const std::string TEST_PATH = "~/git/Alexs-salt-tool-cpp";

        static void Setup();
    protected:

    private:
};

#endif // TESTING_H
