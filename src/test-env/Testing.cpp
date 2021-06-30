#include "Testing.h"

#include "Files.h"

bool Testing::isTestMode = false;

const std::string Testing::TEST_PATH = "~/git/Alexs-salt-tool-cpp/test_files";
const std::string Testing::TEST_IN_ACCEPT = TEST_PATH + "/accepted.tmp";
const std::string Testing::TEST_LIST_IN = TEST_PATH + "/test_in.tmp";

void Testing::Setup(){
    printf("copying test files to temp directory\n");
    bool success = Files::copyFile(TEST_IN_ACCEPT.c_str(), Files::TEMP_PATH.c_str());

}



