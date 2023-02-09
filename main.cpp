#include <iostream>
#include "get_magic_number.h"
#include "check_value.h"
#include "high_scores.h"

void play(){
    // здесь необходимо задать форматированое выравнивание в консоли    
    int magic_number;
    user u;
    std::cout << "Hi! Enter your name, please: ";
    std::cin >> u.name;
    while (u.max_value <= 0) {
        std::cout << "Enter guess number max value: ";
        std::cin >> u.max_value;
    }
    magic_number = get_magic_number(u.max_value);
    check_value(magic_number, u);
}

int main (int argc, char* argv[]){
    std::cout << "-=Guess Number Game=-" << std::endl;
    play();
    std::system("pause");
    return 0;
}