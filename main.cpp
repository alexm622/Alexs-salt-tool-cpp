//    _   _           _      __       _ _     _____            _
//   /_\ | | _____  _( )__  / _\ __ _| | |_  /__   \___   ___ | |
//  //_\\| |/ _ \ \/ // __| \ \ / _` | | __|   / /\/ _ \ / _ \| |
// /  _  \ |  __/>  < \__ \ _\ \ (_| | | |_   / / | (_) | (_) | |
// \_/ \_/_|\___/_/\_\|___/ \__/\__,_|_|\__|  \/   \___/ \___/|_|


#include <iostream>
#include <string>
#include "Options.h"
#include "Utils.h"




int main()
{
    Utils::createTemp();
    Utils::Motd();
    Utils::printOptions();
    std::string s = Utils::Read();
    int option = 0;
    try
    {
        int option = std::stoi(s);
        switch(option){
            case 1:
                Options::acceptAll();
                break;
        }
    }catch (const std::invalid_argument& e){
        printf("invalid input!\n");
        //this just means that an arg that wasn't an int was entered
    }
}

