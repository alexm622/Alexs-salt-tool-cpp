#include "Testing.h"

#include "Files.h"

bool Testing::isTestMode = false;

const std::string Testing::TEMP_PATH = "/tmp/alexs-salt-tool-cpp";

//the path of the test files
const std::string Testing::TEST_PATH = "/home/alex/git/Alexs-salt-tool-cpp/test_files";
//the test output of a salt-key -A command
const std::string Testing::TEST_IN_ACCEPT_SRC = TEST_PATH + "/accepted.tmp";
const std::string Testing::TEST_IN_ACCEPT_DEST = TEMP_PATH + "/accepted.tmp";
//a list of salt client
const std::string Testing::TEST_LIST_IN_SRC = TEST_PATH + "/test_in.tmp";
const std::string Testing::TEST_LIST_IN_DEST = (TEMP_PATH + "/accepted.tmp");


//the setup method
void Testing::Setup(){
    printf("copying test files to temp directory\n");
    //copy the test files

    bool success = Files::copyFile(TEST_IN_ACCEPT_SRC.c_str(), TEST_IN_ACCEPT_DEST.c_str(), true);
    if(success){
        printf("copying succeeded\n");
    }else{
        printf("copying failed\n");
    }


}




