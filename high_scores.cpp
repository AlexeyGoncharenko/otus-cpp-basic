#include <string>
#include <fstream>
#include <iomanip>
#include "high_scores.h"

bool write_to_file(user u, std::ofstream& file) {	
	if (!file.is_open()) {
		return false;
	} else {
	    file << u.name << std::setw(u.name.length()) << " : " << u.tries_cnt << '\n';
		file.flush();
    }
	return true;
}

bool read_from_file(user u, std::ifstream& file) {
	if (!file.is_open()) {
		return false;
	} else {
		std::string str;
		std::string buff;
		while (true){
			std::getline(file, buff);
			if (!file.eof()) {
				str.append(buff.append("\n"));
			} else {
				break;
			}
		}

		std::cout << str;
        return true;
    }
	// file.flush(); // It is not required
	// file.seekg(0); 

	// std::string other_s_value;
	// file.ignore(); // This is required! :)
	// std::getline(file, other_s_value);
}

bool high_scores(const user u, const std::string file_name) {
	std::ofstream o_file{file_name, std::ios_base::in | std::ofstream::app};
    std::ifstream i_file{file_name};
    if (!write_to_file(u, o_file)) {
        std::cout << "Error! Write data to " << file_name.c_str() << std::endl;
	    o_file.close(); // Close file to flush all data
        return false;
    }
    if (!read_from_file(u, i_file)) {
        std::cout << "Error! Read data from " << file_name.c_str() << std::endl;
		i_file.close();
        return false;
    }
    return true;
}