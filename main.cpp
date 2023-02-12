#include <iostream>
#include "get_magic_number.h"
#include "check_value.h"
#include "high_scores.h"

void play(int argc, char* argv[]){
    // add code to check argv: max, table, level, high scores file_name
    int magic_number;
    user u;
    std::string file_name ="high_scores.log";
    std::cout << "Hi! Enter your name: ";
    std::cin >> u.name;
    while (u.max_value <= 0) {
        std::cout << "Enter guess number max value: ";
        std::cin >> u.max_value;
    }
    magic_number = get_magic_number(u.max_value);
    check_value(magic_number, u);
    int result = high_scores(u, file_name);

}

int main (int argc, char* argv[]){
    std::cout << "-=Guess The Number Game=-" << std::endl;
    play(argc, argv);
    return 0;
}