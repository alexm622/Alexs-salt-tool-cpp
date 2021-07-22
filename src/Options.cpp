#include "Options.h"

#include <cstdint>
#include <unistd.h>
#include <iostream>
#include <string>
#include <unistd.h>

#include "Execution.h"
#include "Files.h"
#include "StringTools.h"
#include "Testing.h"
#include "Input.h"

//"accept all awaiting clients",
//"accept and freshload all waiting clients",
//"freshload all clients from a list of clients",
//"execute a salt command across a list of clients",
//"execute a script across a group of clients",
//"use chocolatey to install something across a group of clients",
//reinstall chocolatey across a group of clients,
//single client options
//"prepare test environment",
//"Quit"

//the acceptall function
int8_t Options::acceptAll(){

    printf("Accepting All\n");

    //get the users uid
    uid_t uid = getuid();
    //print the user's uid
    printf(("the uid is " + std::to_string(uid) + "\n").c_str());
    //do salt-key -A and append the input into a temp file
    std::string s = Execution::exec(("echo -e \"y\\r\" | salt-key -A >" + Files::TEMP_PATH + "/accepted.tmp ").c_str());
    //print the output of the command (there shouldnt be any)
    printf(("output: " + s).c_str());

    //quit successfully
    return 0;
}

int8_t Options::acceptAndLoad(){
    std::deque<std::string> clients = StringTools::getAcceptable(StringTools::clean_input(Files::readFile(Testing::TEST_LIST_IN_DEST)));
    for(int i = 0; i < clients.size(); i++){
        if(i%5==0 && i!=0){
            printf("sleeping for 600 seconds \n");
            sleep(600);
        }
        Execution::exec(("salt " + clients[i] + " state.apply scripts.freshload -t600&").c_str());
    }

    return 0;

}

int8_t Options::FreshloadFile(){
    printf("Executing freshload from a list of clients\n");
    printf(("Enter file with list of clients: [" + Files::TEMP_PATH + "/accepted.tmp]:").c_str());
    std::string input (Input::Read());

    if(input.compare("(none)")==0){
        printf("picking default\n");
        input = Files::TEMP_PATH + "/accepted.tmp";
    }

    if(Files::checkForFile(input)==-1){
        printf("file not found\n");
        return -1;
    }


    std::deque<std::string> clients = StringTools::clean_input(Files::readFile(input));
    for(int i = 0; i < clients.size(); i++){
        if(i%5==0 && i!=0){
            printf("sleeping for 600 seconds \n");
            sleep(600);
        }
        Execution::exec(("salt " + clients[i] + " state.apply scripts.freshload -t600&").c_str());
    }

    printf("done\n");
    return 1;
}

int8_t Options::executeCommand(){
    printf("Executing a command across a list of clients\n");
    printf(("Enter file with list of clients: [" + Files::TEMP_PATH + "/accepted.tmp]:").c_str());
    std::string input (Input::Read());
    printf("Enter command to execute: ");
    std::string command (Input::Read());

    if(input.compare("(none)")==0){
        printf("picking default\n");
        input = Files::TEMP_PATH + "/accepted.tmp";
    }
    if(Files::checkForFile(input)==-1){
        printf("file not found\n");
        return -1;
    }
    if(command.compare("none")==0){
        printf("command not found\n");
        return -1;
    }

    std::deque<std::string> clients = StringTools::clean_input(Files::readFile(input));
    for(int i = 0; i < clients.size(); i++){
        if(i%5==0 && i!=0){
            printf("sleeping for 600 seconds \n");
            sleep(600);
        }
        Execution::exec(("salt " + clients[i] + " " + command + "&").c_str());
    }
    return 1;
}

int8_t Options::executeScript(){
    printf("Executing a script across a group of clients\n");
    printf(("Enter file with list of clients: [" + Files::TEMP_PATH + "/accepted.tmp]:").c_str());
    std::string input (Input::Read());
    printf("Enter script to execute: ");
    std::string script (Input::Read());

    if(input.compare("(none)")==0){
        printf("picking default\n");
        input = Files::TEMP_PATH + "/accepted.tmp";
    }
    if(script.compare("(none)")==0){
        printf("script not found\n");
        return -1;
    }
    if(Files::checkForFile(input)==-1){
        printf("file not found\n");
        return -1;
    }
    std::deque<std::string> clients = StringTools::clean_input(Files::readFile(input));
    for(int i = 0; i < clients.size(); i++){
        if(i%5==0 && i!=0){
            printf("sleeping for 600 seconds \n");
            sleep(600);
        }
        Execution::exec(("salt " + clients[i] + " state.apply " + script + " -t600&").c_str());
    }
    return 1;
}

int8_t Options::ChocolateyInstall(){
    printf("Installing something across a group of clients\n");
    printf(("Enter file with list of clients: [" + Files::TEMP_PATH + "/accepted.tmp]:").c_str());
    std::string input (Input::Read());
    printf("Enter package to install: ");
    std::string package (Input::Read());

    if(input.compare("(none)")==0){
        printf("picking default\n");
        input = Files::TEMP_PATH + "/accepted.tmp";
    }
    if(package.compare("(none)")==0){
        printf("package not found\n");
        return -1;
    }
    if(Files::checkForFile(input)==-1){
        printf("file not found\n");
        return -1;
    }
    std::deque<std::string> clients = StringTools::clean_input(Files::readFile(input));
    for(int i = 0; i < clients.size(); i++){
        if(i%5==0 && i!=0){
            printf("sleeping for 600 seconds \n");
            sleep(600);
        }
        Execution::exec(("salt " + clients[i] + " state.apply chocolatey.install " + package + " -t600&").c_str());
    }
    return 1;
}

int8_t Options::ChocolateyReinstall(){
    printf("Reinstalling chocolatey on a group of clients\n");
    printf(("Enter file with list of clients: [" + Files::TEMP_PATH + "/accepted.tmp]:").c_str());
    std::string input (Input::Read());
    if(input.compare("(none)")==0){
        printf("picking default\n");
        input = Files::TEMP_PATH + "/accepted.tmp";
    }
    if(Files::checkForFile(input)==-1){
        printf("file not found\n");
        return -1;
    }
    std::deque<std::string> clients = StringTools::clean_input(Files::readFile(input));
    for(int i = 0; i < clients.size(); i++){
        if(i%5==0 && i!=0){
            printf("sleeping for 600 seconds \n");
            sleep(600);
        }
        Execution::exec(("salt " + clients[i] + " chocolatey.bootstrap force=true -t600&").c_str());
    }
    return 1;
}

