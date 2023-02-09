#pragma once
#include <iostream>
int check_value(int magic_number, int max_value) {
    int user_answer(0);
    int user_tries_cnt(0);

    while (true) {
        std::cout << "Enter your guess [0.." << max_value << "], -1 to exit game:"; 
        std::cin >> user_answer;
        user_tries_cnt++;
        if (user_answer == -1) {
            break;
        }else if(user_answer == magic_number) {
            std::cout << user_name << " you win! Your attemps = " << user_tries_cnt << std::endl;
            break;
        }else if(user_answer < magic_number) {
            std::cout << "magic_number greater than " << user_answer << std::endl;
        }else {
            std::cout << "magic_number less than " << user_answer << std::endl;
        }
    }
}