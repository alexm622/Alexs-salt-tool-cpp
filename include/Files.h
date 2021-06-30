#ifndef FILES_H
#define FILES_H

#include <string>
#include <deque>


class Files
{
    public:
        Files();
        virtual ~Files();

        const static std::string TEMP_PATH;

        static int checkForFile(std::string TEMP_PATH);
        static int toChmodValues(const char* chmod);
        static bool copyFile(const char *SRC, const char* DEST);
        static void createTemp();
        static std::deque<std::string> readFile(std::string file);

    protected:

    private:
};

#endif // FILES_H
