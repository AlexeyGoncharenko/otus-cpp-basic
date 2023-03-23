#pragma once
#include <iostream>

struct player{
    public:
        std::string name;
        int max_value;
        int tries_cnt;
        
        player() {
            name = "";
            max_value = 0;
            tries_cnt = 0;
        }
};

void check_value(const int magic_number, player& player);