#include "Files.h"

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "Utils.h"


const std::string Files::TEMP_PATH = "/tmp/alexs-salt-tool-cpp";

struct stat info;

int Files::toChmodValues(const char* chmod){
    std::string temp;

    for(int i=0; i<3; i++){
        temp += Utils::decToBinary(chmod[i]);
        //printf((temp + "\n").c_str());
    }

    return Utils::binaryToDecimal(std::stoi(temp.c_str()));
}


int Files::checkForFile(std::string TEMP_PATH){
    if( stat( TEMP_PATH.c_str(), &info ) != 0 ){
        //printf( "%s does not exist or cannot access\n", TEMP_PATH.c_str() );
        return -1;
    }else if( info.st_mode & S_IFDIR ){  // S_ISDIR() doesn't exist on my windows
        //printf( "%s is a directory\n", TEMP_PATH.c_str() );
        return 0;
    }else{
        //printf( "%s is not a directory\n", TEMP_PATH.c_str() );
        return 1;
    }
}

void Files::createTemp(){
    if(checkForFile(TEMP_PATH) != 0){
        printf("file does not exist\n");
        uid_t uid = getuid();
        if(uid != 0){
            Utils::exec(("mkdir " + TEMP_PATH).c_str());
            chmod(TEMP_PATH.c_str(), toChmodValues("777"));
        }else{
            std::string username = Utils::exec("getent passwd 1000 | cut -d: -f1");
            Utils::exec(("runuser -u" + username + " -- mkdir " + TEMP_PATH).c_str());
            chmod(TEMP_PATH.c_str(), toChmodValues("777"));

        }

        if(checkForFile("/tmp/alexs-salt-tool-cpp")!=0){
            printf("something went wrong\n");
        }
    }else{
        //printf("folder exists\n");

        chmod(TEMP_PATH.c_str(), toChmodValues("777"));
    }
}




