#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils
{
    public:
        Utils();
        virtual ~Utils();

        static std::string options[];


        static void Motd();
        static void Cls();
        static std::string Read();
        static std::string exec(const char* cmd);
        static std::string exec(const char* cmd, bool overrideTesting);
        static void printOptions();

        static int binaryToDecimal(int n);
        static std::string decToBinary(int n);

    protected:

    private:
};

#endif // UTILS_H
