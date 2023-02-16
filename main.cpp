#include <iostream>
#include <vector>
#include "get_magic_number.h"
#include "check_value.h"
#include "high_scores.h"
#define MAX_NAME_LENGTH 15 

struct args_list {
    std::string name;
    int value;
};

args_list tmp;
std::vector<args_list> prm;

bool play(int argc, char* argv[]){
    // add code to check argv: max, table, level, high scores file_name
    int magic_number;
    user u;
    std::string file_name ="high_scores.log";
    std::string max_value_str; // to fix infinite loop, if std::cin trying to set string data to integer

    std::cout << "Hi! Enter your name: ";
    std::cin >> u.name;
    
    u.name.resize(MAX_NAME_LENGTH);

    do {
        std::cout << "Enter guess number max value: ";
        std::cin >> max_value_str;
        u.max_value = std::atoi(max_value_str.c_str());
    } while (u.max_value <= 0);

    magic_number = get_magic_number(u.max_value);
    check_value(magic_number, u);
    bool result = high_scores(u, file_name);

    return result;
}

int main (int argc, char* argv[]) {
    std::cout << "-=Guess The Number Game=-" << std::endl;
    
    for (size_t i = 0; i < argc; ) {
        if (std::atoi(argv[i]) == 0) { // is param_name
            if ((i + 1 < argc) && std::atoi(argv[i + 1]) != 0) { // is param_value
                tmp.name = argv[i];
                tmp.value = std::atoi(argv[i + 1]);
                prm.push_back(tmp);
                i += 2; // next param
            } else {
                i++; // incomplete pair
            }
        }
    }
    
    for (args_list &t : prm)
    {
        std::cout << t.name.c_str() << '=' << t.value << std::endl;
    }
    
    
    // if (play(argc, argv)) {
    //     return 0;
    // }else {
    //     return 1;
    // }
}