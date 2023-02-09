#include <iostream>
#include <random>
int main (int agrc, char* argv[]){
    // здесь необходимо задать выравние в консоли
    std::string greetings = "-=Guess Number Game=-";
    std::cout << greetings.c_str() << "\nHi! Enter your name, please: ";

    const int max_value = 100;
    std::srand(std::time(nullptr));
    int magic_number = std::rand() % max_value;
   
    std::string user_name;
    int user_answer;
    int tries_cnt;
    return 0;
}