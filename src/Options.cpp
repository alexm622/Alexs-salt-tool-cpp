#include "Options.h"

#include <cstdint>
#include <unistd.h>
#include <iostream>
#include <Utils.h>
#include <string>

//"accept all awaiting clients",
//"accept and freshload all waiting clients",
//"freshload all clients from a list of clients",
//"execute a command across a list of clients",
//"execute a script across a group of clients",
//"use chocolatey to install something across a group of clients",
//"prepare test environment",
//"Quit"

Options::Options()
{
    //ctor
}

Options::~Options()
{
    //dtor
}

int8_t Options::acceptAll(){

    printf("Accepting All\n");

    uid_t uid = getuid();
    printf(("the uid is " + std::to_string(uid) + "\n").c_str());
    printf("before\n");
    std::string s = Utils::exec("echo -e \"y\\r\" | salt-key -A > /tmp/alexs-salt-tool-cpp/accepted.tmp ");
    printf("after\n");
    printf(("output: " + s).c_str());

    return 0;
}


