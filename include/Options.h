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


    protected:

    private:
};

#endif // OPTIONS_H
