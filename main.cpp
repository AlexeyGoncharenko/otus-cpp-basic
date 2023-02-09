#include <iostream>
#include "get_magic_number.h"
#include "check_value.h"
#include "high_scores.h"

struct game_info{
    std::string user_name;
    int user_tries_cnt;
} user;

void play(){
    // здесь необходимо задать форматирование выравнивание в консоли    
    int max_value = 0;
    int magic_number = 0;
    std::cout << "Hi! Enter your name, please: ";
    std::cin >> user.user_name;
    std::cout << "Enter guess number max value: ";
    std::cin >> max_value;
    magic_number = get_magic_number(max_value);
    check_value(magic_number, max_value);
}

int main (int argc, char* argv[]){
    std::cout << "-=Guess Number Game=-" << std::endl;
    play();
    std::system("pause");
    return 0;
}