#include "check_value.h"

void check_value(int magic_number, user& u) {
    int answer;
    while (true) {
        std::cout << "Enter your guess [0.." << u.max_value - 1 << "]: "; 
        std::cin >> answer;
        u.tries_cnt++;
        if (answer == magic_number) {
            std::cout << u.name << " you win! Your attemps = " << u.tries_cnt << std::endl;
            break;
        }else if(answer < magic_number) {
            std::cout << "magic_number greater than " << answer << std::endl;
        }else {
            std::cout << "magic_number less than " << answer << std::endl;
        }
    }
}