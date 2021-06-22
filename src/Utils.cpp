#include "Utils.h"

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>


Utils::Utils()
{
    //ctor
}

Utils::~Utils()
{
    //dtor
}

void Utils::Motd(){
    printf("   _   _           _      __       _ _     _____            _ \n");
    printf("  /_\\ | | _____  _( )__  / _\\ __ _| | |_  /__   \\___   ___ | |\n");
    printf(" //_\\\\| |/ _ \\ \\/ // __| \\ \\ / _\\ | | __|   / /\\/ _ \\ / _ \\| |\n");
    printf("/  _  \\ |  __/>  < \\__ \\ _\\ \\ (_| | | |_   / / | (_) | (_) | |\n");
    printf("\\_/ \\_/_|\\___/_/\\_\\|___/ \\__/\\__,_|_|\\__|  \\/   \\___/ \\___/|_|\n");
    printf("                                                              \n");
}

void Utils::Cls(){
    printf("\033c");
}

std::string Utils::Read(){
    std::string s;
    std::cin >> s;

    return s;
}



std::string Utils::exec(const char* cmd) {
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
