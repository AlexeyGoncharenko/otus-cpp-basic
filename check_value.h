#include <iostream>
#ifndef __GUARDED_HPP
#define __GUARDED_HPP
struct user{
    public:
        std::string name;
        int tries_cnt;
        int max_value;
    user(){
        name = "";
        tries_cnt = 0;
        max_value = 0;
    }
};
#endif // __GUARDED_HPP

void check_value(int, user&);