#ifndef OUT_H
#define OUT_H

#include "string"

class Out
{
    public:
        Out();
        virtual ~Out();

        static std::string options[];

        static void Motd();
        static void Cls();

        static void printOptions();

    protected:

    private:
};

#endif // OUT_
