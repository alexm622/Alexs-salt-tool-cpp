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
//"execute a command across a list of clients",
//"execute a script across a group of clients",
//"use chocolatey to install something across a group of clients",
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

}

int8_t Options::FreshloadFile(){
    printf("Executing freshload from a list of clients\n");
    printf(("Enter file with list of clients: [" + Files::TEMP_PATH + "/accepted.tmp]:").c_str());
    std::string input = "";
    std::string input += Input::Read();
    printf("read success\n");
    printf("string length %d", input.length());
    printf("the value of input is %s", input.c_str());
    if(input.empty()){
        printf("pick default");
    }
    printf("done");

}


