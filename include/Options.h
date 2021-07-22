#ifndef OPTIONS_H
#define OPTIONS_H

#include <cstdint>

class Options
{
    public:
        Options();
        virtual ~Options();
        static int8_t acceptAll();
        static int8_t acceptAndLoad();
        static int8_t FreshloadFile();
        static int8_t executeCommand();
        static int8_t executeScript();
        static int8_t ChocolateyInstall();
        static int8_t ChocolateyReinstall();


    protected:

    private:
};

#endif // OPTIONS_H
