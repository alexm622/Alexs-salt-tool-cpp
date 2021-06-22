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

    protected:

    private:
};

#endif // UTILS_H
