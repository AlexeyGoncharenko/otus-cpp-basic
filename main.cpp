#include <iostream>
#include "get_magic_number.h"
#include "check_value.h"
#include "high_scores.h"

struct args_list {
    public:
        std::string name;
        int value;

        args_list() {
            name = "";
            value = 0;
        }

        args_list(std::string n, int v = 0): name(n), value(v){}

        bool operator==(args_list& a) {
            if (this->name == a.name) return true; // to compare only name
            else return false;
        }

        void set(std::string &n, int v = 0) {
            this->name = n;
            this->value = v;
        }
};

int arg_is_available(args_list x, std::vector<args_list> &p) {
   int size = (int)p.size();
    for (int i = 0; i < size; i++) {
        if (p[i] == x) {
           return i; // return index of appropriate parameter 
        }
    }
    return -1;
}

void parse_args(int argc, char* argv[], std::vector<args_list> &p){
    args_list tmp;
    for (size_t i = 0; i < argc; ) {
        if (std::atoi(argv[i]) == 0) { // is param_name
            if ((i + 1 < argc) && std::atoi(argv[i + 1]) != 0) { // is param_value
                tmp.name = argv[i];
                tmp.value = std::atoi(argv[i + 1]);
                p.push_back(tmp);
                i += 2; // next param
            } else { // incomplete pair or single one
                tmp.name = argv[i];
                tmp.value = 0;
                p.push_back(tmp);
                i++; 
            }
        }
    }
}

bool play(std::vector<args_list> &p){
    std::string file_name ="high_scores.log";
    bool result = false;
    int magic_number, idx;
    user u;

    // check arguments: -table
    idx = arg_is_available(args_list("-table"), p);
    if (idx != -1) {
        result = high_scores(u, file_name, 1);
        return result;
    }
 
     // -max and -level arguments mutually exclusive
    if (arg_is_available(args_list("-max"), p) != -1 && arg_is_available(args_list("-level"), p) != -1) {
        return result;
    }

    // check arguments: -level && -max
    std::string max_value_str; // to fix infinite loop if std::cin trying to set symbol data to int
    std::cout << "Hi! Enter your name: ";
    std::cin >> u.name;

    idx = arg_is_available(args_list("-level"), p);
    if (idx != -1) {
        switch (p[idx].value)
        {
            case 1: // u.max_value=[0..9] 
                u.max_value = 10;
                break;
            case 2: // u.max_value=[0..49] 
                u.max_value = 50;
                break;
            case 3: // u.max_value=[0..99] 
                u.max_value = 100;
                break;
            default:
                return result;
        }

        magic_number = get_magic_number(u.max_value);
        check_value(magic_number, u);
        result = high_scores(u, file_name, 0);

        return result;

    } else {
        idx = arg_is_available(args_list("-max"), p);
        if (idx != -1) {
            u.max_value = p[idx].value;
        } else {
            do {
                std::cout << "Enter guess number max value: ";
                std::cin >> max_value_str;
                u.max_value = std::atoi(max_value_str.c_str());
            } while (u.max_value <= 0); 
        }
      
        magic_number = get_magic_number(u.max_value);
        check_value(magic_number, u);
        result = high_scores(u, file_name, 0);

        return result;
    }
}

int main (int argc, char* argv[]) {
    std::cout << "-=Guess The Number Game=-" << std::endl;    

    std::vector<args_list> prms;
    parse_args(argc, argv, prms);

    if (play(prms)) {
        return 0;
    }else {
        std::cout << "Check correct parameters input\n" << argv[0] << " [-max <int> ] [-level 1..3] [-table]\n[-max] [-level] mutually exclusive" << std::endl;
        return 1;
    }
}