#include "Out.h"

#include "Testing.h"

std::string Out::options[] = {
    "accept all awaiting clients",
    "accept and freshload all waiting clients",
    "freshload all clients from a list of clients",
    "execute a command across a list of clients",
    "execute a script across a group of clients",
    "use chocolatey to install something across a group of clients",
    "prepare test environment",
    "enable testing mode",
    "Quit"
}; //NO WRITING TO THIS

void Out::Motd(){
    printf("   _   _           _      __       _ _     _____            _ \n");
    printf("  /_\\ | | _____  _( )__  / _\\ __ _| | |_  /__   \\___   ___ | |\n");
    printf(" //_\\\\| |/ _ \\ \\/ // __| \\ \\ / _\\ | | __|   / /\\/ _ \\ / _ \\| |\n");
    printf("/  _  \\ |  __/>  < \\__ \\ _\\ \\ (_| | | |_   / / | (_) | (_) | |\n");
    printf("\\_/ \\_/_|\\___/_/\\_\\|___/ \\__/\\__,_|_|\\__|  \\/   \\___/ \\___/|_|\n");
    printf("                                                              \n");
    if(Testing::isTestMode){
        printf("Testing mode is enabled\n");
    }
}

void Out::printOptions(){
    int i = 0;
    for(std::string s: options){
        i++;
        std::string str = std::to_string(i) + ") " + s + "\n";
        printf(str.c_str());
    }
}

void Out::Cls(){
    printf("\033c");
}
