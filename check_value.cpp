#include "check_value.h"

void check_value(const int magic_number, player& player) {
    int answer;
    while (true) {
        std::cout << "Enter your guess [0.." << player.max_value - 1 << "]: "; 
        std::cin >> answer;
        player.tries_cnt++;
        if (answer == magic_number) {
            std::cout << player.name << " you win! Your attemps = " << player.tries_cnt << std::endl;
            break;
        }else if(answer < magic_number) {
            std::cout << "magic_number greater than " << answer << std::endl;
        }else {
            std::cout << "magic_number less than " << answer << std::endl;
        }
    }
}