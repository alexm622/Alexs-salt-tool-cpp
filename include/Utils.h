#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils
{
    public:
        Utils();
        virtual ~Utils();
        const static std::string TEMP_PATH;
        static std::string options[];

        static void createTemp();
        static void Motd();
        static void Cls();
        static std::string Read();
        static std::string exec(const char* cmd);
        static void printOptions();
        static int checkForFile(std::string TEMP_PATH);
        static int binaryToDecimal(int n);
        static int toChmodValues(const char* chmod);
        static std::string decToBinary(int n);

    protected:

    private:
};

#endif // UTILS_H
