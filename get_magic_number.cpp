#pragma once
#include <cstdlib>
#include <ctime>
int get_magic_number(const int max_value) {
    std::srand(std::time(nullptr));
    int magic_number = std::rand() % max_value;
    return magic_number;
}