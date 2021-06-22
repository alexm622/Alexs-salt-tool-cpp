//    _   _           _      __       _ _     _____            _
//   /_\ | | _____  _( )__  / _\ __ _| | |_  /__   \___   ___ | |
//  //_\\| |/ _ \ \/ // __| \ \ / _` | | __|   / /\/ _ \ / _ \| |
// /  _  \ |  __/>  < \__ \ _\ \ (_| | | |_   / / | (_) | (_) | |
// \_/ \_/_|\___/_/\_\|___/ \__/\__,_|_|\__|  \/   \___/ \___/|_|


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>



std::unordered_map<int, std::string> options;

std::string read(){
    std::string s;
    std::cin >> s;

    return s;
}

void motd(){
    printf("   _   _           _      __       _ _     _____            _ \n");
    printf("  /_\\ | | _____  _( )__  / _\\ __ _| | |_  /__   \\___   ___ | |\n");
    printf(" //_\\\\| |/ _ \\ \\/ // __| \\ \\ / _\\ | | __|   / /\\/ _ \\ / _ \\| |\n");
    printf("/  _  \\ |  __/>  < \\__ \\ _\\ \\ (_| | | |_   / / | (_) | (_) | |\n");
    printf("\\_/ \\_/_|\\___/_/\\_\\|___/ \\__/\\__,_|_|\\__|  \\/   \\___/ \\___/|_|\n");
    printf("                                                              \n");
}

void cls(){
    printf("\033c");
}

void initOptions(){
    options[1] = " accept all awaiting clients";
}

void printOptions(){
    int i = 0;
    for(auto s: options){
        i++;
        std::string str = std::to_string(i) + ") " + s.second;
        printf(str.c_str());
    }
}


int main()
{
    motd();
    initOptions();
    printOptions();
    std::string s = read();
    printf(s.c_str());

}

