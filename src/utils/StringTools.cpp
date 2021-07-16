#include "StringTools.h"

std::deque<std::string> StringTools::clean_input(std::deque<std::string> input){
    input.pop_front();
    input.pop_front();
    input.pop_back();
    return input;
}

std::deque<std::string> StringTools::getAcceptable(std::deque<std::string> input){
    std::deque<std::string> output;
    for (int i = 0; i < input.size(); i++) {
        if(input[i].find("remi-") != std::string::npos){
            output.push_back(input[i]);
        }
    }
    return output;

}

