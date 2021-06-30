#ifndef FILES_H
#define FILES_H

#include <string>


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

    protected:

    private:
};

#endif // FILES_H
