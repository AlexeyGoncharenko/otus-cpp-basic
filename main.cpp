#include <iostream>
#include "get_magic_number.h"
#include "check_value.h"
#include "high_scores.h"

struct arg {
    public:
        std::string name;
        int value;

        arg() {
            name = "";
            value = 0;
        }

        arg(std::string n, int v = 0): name(n), value(v){}

        bool operator==(const arg& a) const {
            if (this->name == a.name) return true; // to compare only name
            else return false;
        }

        void set(std::string &n, int v = 0) {
            this->name = n;
            this->value = v;
        }
};

int arg_is_available(const arg x, const std::vector<arg> &args_list) {
   int size = (int)args_list.size();
    for (int i = 0; i < size; i++) {
        if (args_list[i] == x) {
           return i; // return index of appropriate parameter 
        }
    }
    return -1;
}

std::vector<arg> parse_args(int argc, char* argv[]){
    arg tmp;
    std::vector<arg> args_list;
    for (int i = 0; i < argc; ) {
        if (std::atoi(argv[i]) == 0) { // is param_name
            if ((i + 1 < argc) && std::atoi(argv[i + 1]) != 0) { // is param_value
                tmp.name = argv[i];
                tmp.value = std::atoi(argv[i + 1]);
                args_list.push_back(tmp);
                i += 2; // next param
            } else { // incomplete pair or single one
                tmp.name = argv[i];
                tmp.value = 0;
                args_list.push_back(tmp);
                i++; 
            }
        }
    }
    return args_list;
}

bool play(const std::vector<arg> &args_list){
    std::string file_name ="high_scores.log";
    bool result = false;
    int magic_number, idx;
    player player;

    // check arguments: -table
    idx = arg_is_available(arg("-table"), args_list);
    if (idx != -1) {
        result = high_scores(player, file_name, 1);
        return result;
    }
 
     // -max and -level arguments mutually exclusive
    if (arg_is_available(arg("-max"), args_list) != -1 && arg_is_available(arg("-level"), args_list) != -1) {
        return result;
    }

    // check arguments: -level && -max
    std::string max_value_str; // to fix infinite loop if std::cin trying to set symbol data to int
    std::cout << "Hi! Enter your name: ";
    std::cin >> player.name;

    idx = arg_is_available(arg("-level"), args_list);
    if (idx != -1) {
        switch (args_list[idx].value)
        {
            case 1: // u.max_value=[0..9] 
                player.max_value = 10;
                break;
            case 2: // u.max_value=[0..49] 
                player.max_value = 50;
                break;
            case 3: // u.max_value=[0..99] 
                player.max_value = 100;
                break;
            default:
                return result;
        }

        magic_number = get_magic_number(player.max_value);
        check_value(magic_number, player);
        result = high_scores(player, file_name, 0);

        return result;

    } else {
        idx = arg_is_available(arg("-max"), args_list);
        if (idx != -1) {
            player.max_value = args_list[idx].value;
        } else {
            do {
                std::cout << "Enter guess number max value: ";
                std::cin >> max_value_str;
                player.max_value = std::atoi(max_value_str.c_str());
            } while (player.max_value <= 0); 
        }
      
        magic_number = get_magic_number(player.max_value);
        check_value(magic_number, player);
        result = high_scores(player, file_name, 0);

        return result;
    }
}

int main (int argc, char* argv[]) {
    std::cout << "-=Guess The Number Game=-" << std::endl;     

    std::vector<arg> args_list = parse_args(argc, argv);
    if (play(args_list)) {
        return 0;
    }else {
        std::cout << "Check correct parameters input\n" << argv[0] << " [-max <int> ] [-level 1..3] [-table]\n[-max] [-level] mutually exclusive" << std::endl;
        return 1;
    }
}