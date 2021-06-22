#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils
{
    public:
        Utils();
        virtual ~Utils();
        static void Motd();
        static void Cls();
        static std::string Read();
        static std::string exec(const char* cmd);

    protected:

    private:
};

#endif // UTILS_H
