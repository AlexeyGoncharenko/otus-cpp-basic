#include <iostream>

#ifndef __GUARDED_HPP
#define __GUARDED_HPP
struct user{
    public:
        std::string name;
        int max_value;
        int tries_cnt;
    user() {
        name = "";
        max_value = 0;
        tries_cnt = 0;
    }
};
#endif // __GUARDED_HPP

void check_value(int, user&);