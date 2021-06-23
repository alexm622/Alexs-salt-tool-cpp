#ifndef SALT_H
#define SALT_H

#include <string>

class Salt
{
    public:
        Salt();
        virtual ~Salt();
        struct SaltCommand{
            std::string host;
            std::string action;
            std::string args[];
        };


    protected:

    private:
};

#endif // SALT_H
