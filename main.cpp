//    _   _           _      __       _ _     _____            _
//   /_\ | | _____  _( )__  / _\ __ _| | |_  /__   \___   ___ | |
//  //_\\| |/ _ \ \/ // __| \ \ / _` | | __|   / /\/ _ \ / _ \| |
// /  _  \ |  __/>  < \__ \ _\ \ (_| | | |_   / / | (_) | (_) | |
// \_/ \_/_|\___/_/\_\|___/ \__/\__,_|_|\__|  \/   \___/ \___/|_|

//a list of options
//"accept all awaiting clients",
//"accept and freshload all waiting clients",
//"freshload all clients from a list of clients",
//"execute a command across a list of clients",
//"execute a script across a group of clients",
//"use chocolatey to install something across a group of clients",
//reinstall chocolatey across a group of clients,
//"prepare test environment",
//"Quit"

#include <iostream>
#include <string>

#include "Options.h"
#include "Files.h"
#include "Testing.h"
#include "Out.h"
#include "Input.h"
#include "StringTools.h"

//the main function
int main()
{
    //create temporary files
    Files::createTemp();

    //output the motd and print options
    Out::Motd();
    Out::printOptions();

    //read the users first option
    std::string s (Input::Read());
    int option = 0;

    //loop until quit of ctrl^c
    bool quitout = false;
    while(!quitout){
        try
        {
            //convert the option to a string
            int option = std::stoi(s);

            //interpret the option
            switch(option){
                case 0: // this is not a valid option
                    break;
                case 1: //this is accept all
                    Options::acceptAll();
                    break;
                case 2:
                    Options::acceptAndLoad();
                    break;
                case 3:
                    Options::FreshloadFile();
                    break;
                case 4:
                    Options::executeCommand();
                    break;
                case 5:
                    Options::executeScript();
                    break;
                case 6:
                    Options::ChocolateyInstall();
                    break;
                case 7:
                    Options::ChocolateyReinstall();
                    break;
                case 8: //enable test mode
                    Testing::isTestMode = true;
                    Testing::Setup();
                    break;
                case 9: //quit from the loop
                    quitout = true;
                    break;
                default: //the default statement
                    printf("that option does not exist \n");

            }

            //if quitout is true we break to avoid printing motd and options and
            //waiting for anther read
            if(quitout){
                break;
            }

            //print the motd and options for the next iteration
            Out::Motd();
            Out::printOptions();

            //get the input from user
            s = Input::Read();

        }catch (const std::invalid_argument& e){ //user entered something that was not an integer
            printf("invalid input!\n");
            //this just means that an arg that wasn't an int was entered
            s="0";
        }
    }

}

