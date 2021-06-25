#include "Utils.h"

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


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

std::string Utils::options[] = {
    "accept all awaiting clients",
    "accept and freshload all waiting clients",
    "freshload all clients from a list of clients",
    "execute a command across a list of clients",
    "execute a script across a group of clients",
    "use chocolatey to install something across a group of clients",
    "prepare test environment",
    "Quit"
}; //NO WRITING TO THIS




void Utils::printOptions(){
    int i = 0;
    for(std::string s: options){
        i++;
        std::string str = std::to_string(i) + ") " + s + "\n";
        printf(str.c_str());
    }
}

int Utils::binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}

std::string Utils::decToBinary(int n)
{
    // array to store binary number
    int binaryNum[3];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    std::string out;

    for(int in : binaryNum){
        int temp = in;
        out += std::to_string(temp);
    }

    return out;
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







