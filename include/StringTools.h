#ifndef STRINGTOOLS_H
#define STRINGTOOLS_H

#include <deque>
#include <string>

class StringTools
{
    public:
        StringTools();
        virtual ~StringTools();

        static std::deque<std::string> clean_input(std::deque<std::string> input);
        static std::deque<std::string> getAcceptable(std::deque<std::string> input);
    protected:

    private:
};

#endif // STRINGTOOLS_H
