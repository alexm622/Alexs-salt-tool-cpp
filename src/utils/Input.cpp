#include "Input.h"

#include "iostream"

//just read input, its very simple
std::string Input::Read(){
    std::string s;
    std::getline(std::cin, s);

    return s;
}
