#include "Files.h"


#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>

#include "Math.h"
#include "Execution.h"

//the path of the temp files folder
const std::string Files::TEMP_PATH = "/tmp/alexs-salt-tool-cpp";

//convert a string of chmod values i.e. "777" to the proper acceptable input
int Files::toChmodValues(const char* chmod){
    std::string temp;

    //convert each of the characters of the inputted string into their binary equivalents and append
    for(int i=0; i<3; i++){
        temp += Math::decToBinary(chmod[i]);
        //printf((temp + "\n").c_str());
    }
    //get the value of chmod as its binary equivalent "777" -> "111111111", and convert to an integer value
    return Math::binaryToDecimal(std::stoi(temp.c_str()));
}


int Files::checkForFile(std::string TEMP_PATH){
    struct stat info;
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

bool Files::file_exists(std::string name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

void Files::createTemp(){
    //if the file does not exist then we will create the temp folder
    if(checkForFile(TEMP_PATH) != 0){
        printf("file does not exist\n");
        //get the user's current uid
        uid_t uid = getuid();
        //if the uid is not root
        if(uid != 0){
            //create the folder as the user and give all permissions to everyone on it
            Execution::exec(("mkdir " + TEMP_PATH).c_str(), true);
            chmod(TEMP_PATH.c_str(), toChmodValues("777"));
        }else{ //if the script is being run as root we want to get the username of the user with the uid 1000, make the folder as them, and then set perms
            //get the username
            std::string username = Execution::exec("getent passwd 1000 | cut -d: -f1", true);
            //run mkdir as the user with the uid of 1000
            Execution::exec(("runuser -u" + username + "= -- mkdir " + TEMP_PATH).c_str(), true);
            //chmod the temp folder to fit the needs
            chmod(TEMP_PATH.c_str(), toChmodValues("777"));

        }
        //if the file still does not exist thrown and error or at least say something went wrong
        if(checkForFile("/tmp/alexs-salt-tool-cpp")!=0){
            printf("something went wrong\n");
        }
    }else{
        //printf("folder exists\n");
        //just reinforce the perms
        // TODO this should force reinforce is the user is root
        // and skip over that step if the current user does not own that directory
        chmod(TEMP_PATH.c_str(), toChmodValues("777"));
    }
}

//copy a file
bool Files::copyFile(const char *SRC, const char* DEST)
{
    //get input file stream of source file
    std::ifstream src(SRC, std::ios::binary);
    //get output file stream of destination file
    std::ofstream dest(DEST, std::ios::binary);
    //this is pretty straightforward, read the file into the new one
    dest << src.rdbuf();
    //if this succeeded return true
    return src && dest;
}
bool Files::copyFile(const char *SRC, const char* DEST, bool overwrite)
{
    if(overwrite && file_exists((std::string)DEST)){
        unlink(DEST);
    }
    //get input file stream of source file
    std::ifstream src(SRC, std::ios::binary);
    //get output file stream of destination file
    std::ofstream dest(DEST, std::ios::binary);
    //this is pretty straightforward, read the file into the new one
    dest << src.rdbuf();
    //if this succeeded return true
    return src && dest;
}

std::deque <std::string> Files::readFile(std::string file){
    std::deque<std::string> output;

    std::string line;
    std::ifstream myfile (file);
    if (myfile.is_open())
    {
    while ( getline (myfile,line) )
    {
        output.push_back(line);
    }
        myfile.close();
    }



    return output;
}





