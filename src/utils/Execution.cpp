#include "Execution.h"

#include "array"
#include <memory>

#include "Testing.h"


std::string Execution::exec(const char* cmd) {
    if(Testing::isTestMode){
        return ("Testing mode is enabled. the executed command would be: "+ (std::string) cmd);
    }
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string Execution::exec(const char* cmd, bool overrideTesting=false) {
    if(Testing::isTestMode && !overrideTesting){
        return ("Testing mode is enabled. the executed command would be" + (std::string) cmd);
    }else if(Testing::isTestMode){
        printf("testing mode is on, but this exec is set to override\n");
        printf(("Testing mode is enabled. the executed command would be" + (std::string) cmd).c_str());
    }
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}
