#include "Testing.h"

#include "Files.h"

bool Testing::isTestMode = false;

//the path of the test files
const std::string Testing::TEST_PATH = "/home/alex/git/Alexs-salt-tool-cpp/test_files";
//the test output of a salt-key -A command
const std::string Testing::TEST_IN_ACCEPT = TEST_PATH + "/accepted.tmp";
//a list of salt client
const std::string Testing::TEST_LIST_IN = TEST_PATH + "/test_in.tmp";

//the setup method
void Testing::Setup(){
    printf("copying test files to temp directory\n");
    //copy the test files

    bool success = Files::copyFile(TEST_IN_ACCEPT.c_str(), (Files::TEMP_PATH+ "/accepted.tmp").c_str());
    if(success){
        printf("copying succeeded\n");
    }else{
        printf("copying failed\n");
    }


}




