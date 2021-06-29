#ifndef EXECUTION_H
#define EXECUTION_H

#include "string"

class Execution
{
    public:
        Execution();
        virtual ~Execution();

        static std::string exec(const char* cmd);
        static std::string exec(const char* cmd, bool overrideTesting);

    protected:

    private:
};

#endif // EXECUTION_H
