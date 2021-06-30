#include "Options.h"

#include <cstdint>
#include <unistd.h>
#include <iostream>
#include <string>

#include "Execution.h"
#include "Files.h"

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


