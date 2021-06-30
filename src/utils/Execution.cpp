#include "Execution.h"

#include "array"
#include <memory>

#include "Testing.h"

//execution without a testing mode based flag, this will automaticaally print if testing mode is enabled
std::string Execution::exec(const char* cmd) {
    //if testing mode is on then we will print the command instead
    if(Testing::isTestMode){
        printf(("Testing mode is enabled. the executed command would be" + (std::string) cmd + "/n").c_str());
        return ("Testing mode is enabled. the executed command would be: "+ (std::string) cmd);
    }
    std::array<char, 128> buffer;
    std::string result;

    //create a pipe
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    //could not create pipe
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    //get the date from the pipe
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}
//testing mode but with a testing mode override
//use this carefully
std::string Execution::exec(const char* cmd, bool overrideTesting=false) {
    if(Testing::isTestMode && !overrideTesting){
        printf(("Testing mode is enabled. the executed command would be" + (std::string) cmd + "/n").c_str());
        return ("Testing mode is enabled. the executed command would be" + (std::string) cmd);
    }else if(Testing::isTestMode){ //testing mode
        printf("testing mode is on, but this exec is set to override\n");
        printf(("Testing mode is enabled. the executed command would be" + (std::string) cmd).c_str());
    }
    std::array<char, 128> buffer;
    std::string result;

    //create a pipe
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    //could not create pipe
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    //get the date from the pipe
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}
