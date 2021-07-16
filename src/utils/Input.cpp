#include "Input.h"

#include "iostream"

//just read input, its very simple
std::string Input::Read(){
    std::string s;
    std::getline(std::cin, s);
    if(s.length()==0){
        printf("returning none\n");
        return "(none)";
    }else{
        return s;
    }
}
