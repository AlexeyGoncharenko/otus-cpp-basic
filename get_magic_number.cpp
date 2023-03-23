#include <cstdlib>
#include <ctime>
#include "get_magic_number.h"

int get_magic_number(const int max_value) {
    std::srand((unsigned int)std::time(nullptr));
    int magic_number = std::rand() % max_value;
    return magic_number;
}