//    _   _           _      __       _ _     _____            _
//   /_\ | | _____  _( )__  / _\ __ _| | |_  /__   \___   ___ | |
//  //_\\| |/ _ \ \/ // __| \ \ / _` | | __|   / /\/ _ \ / _ \| |
// /  _  \ |  __/>  < \__ \ _\ \ (_| | | |_   / / | (_) | (_) | |
// \_/ \_/_|\___/_/\_\|___/ \__/\__,_|_|\__|  \/   \___/ \___/|_|


#include <iostream>
#include <string>

#include "Options.h"
#include "Files.h"
#include "Testing.h"
#include "Out.h"
#include "Input.h"




int main()
{
    Files::createTemp();
    Out::Motd();
    Out::printOptions();
    std::string s = Input::Read();
    int option = 0;
    bool quitout = false;
    while(!quitout){
        try
        {

            int option = std::stoi(s);
            switch(option){
                case 0:
                    break;
                case 1:
                    Options::acceptAll();
                    break;
                case 8:
                    Testing::isTestMode = true;
                    break;
                case 9:
                    quitout = true;
                    break;
                default:
                    printf("that option does not exist \n");

            }
            if(quitout){
                break;
            }
            Out::Motd();
            Out::printOptions();
            s = Input::Read();

        }catch (const std::invalid_argument& e){
            printf("invalid input!\n");
            //this just means that an arg that wasn't an int was entered
            s="0";
        }
    }

}

