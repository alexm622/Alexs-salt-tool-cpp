//    _   _           _      __       _ _     _____            _
//   /_\ | | _____  _( )__  / _\ __ _| | |_  /__   \___   ___ | |
//  //_\\| |/ _ \ \/ // __| \ \ / _` | | __|   / /\/ _ \ / _ \| |
// /  _  \ |  __/>  < \__ \ _\ \ (_| | | |_   / / | (_) | (_) | |
// \_/ \_/_|\___/_/\_\|___/ \__/\__,_|_|\__|  \/   \___/ \___/|_|


#include <iostream>
#include <string>
#include "Options.h"
#include "Utils.h"


std::string options[] = {
    "accept all awaiting clients",
    "accept and freshload all waiting clients",
    "freshload all clients from a list of clients",
    "execute a command across a list of clients",
    "execute a script across a group of clients",
    "use chocolatey to install something across a group of clients",
    "prepare test environment",
    "Quit"};




void printOptions(){
    int i = 0;
    for(std::string s: options){
        i++;
        std::string str = std::to_string(i) + ") " + s + "\n";
        printf(str.c_str());
    }
}


int main()
{
    Utils::Motd();
    printOptions();
    std::string s = Utils::Read();
    printf(s.c_str());

}

