#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "high_scores.h"

bool write_to_file(const player &player, const std::string& file_name) {	
	// to use a file stream in read/write mode, ensure the file exists first
	std::fstream o_file{file_name, std::ios_base::out | std::ios_base::app};
	o_file.close();
	o_file.open(file_name, std::ios_base::in);
	//
	
	// read file first
	if (o_file.is_open()) {	
		// find and replace
		o_file.seekg(0); 
		bool is_found = false;
		std::string line;
		std::vector<std::string> lines;
		std::stringstream ss;
		ss << player.name << " " << player.tries_cnt;
		
		while (std::getline(o_file, line)) { // find exist player
			if (line.find(player.name) != std::string::npos) {
				if (std::atoi((line.substr((player.name).length() + 1, line.length())).c_str()) > player.tries_cnt) {
					line.replace(0, line.size(), ss.str());
				}
				is_found = true;
			}
			lines.push_back(line);
		}
		
		if (!is_found) { // add new player
			lines.push_back(ss.str());
		}
		o_file.close();

		// rewrite file than
		o_file.open(file_name, std::ios_base::out | std::ios_base::trunc);
		
		for (const auto& l: lines) {
			o_file << l << std::endl;
		}

		return true;
	} else {
		return false;
    }
}

bool read_from_file(const std::string& file_name) {
    std::fstream i_file{file_name, std::ios_base::in};
	if (i_file.is_open()) {
		std::string str, line;

		while (!i_file.eof()){
			std::getline(i_file, line);
			str.append(line.append("\n"));
		}

		std::cout << str.c_str();
        return true;
	} else {
		return false;
    }
}

bool high_scores(const player &player, const std::string& file_name, const uint32_t open_mode) {
	bool result = true;

	switch (open_mode) {
		case 0: // write and read
			if (!write_to_file(player, file_name)) {
				std::cout << "Error! Write data to " << file_name.c_str() << std::endl;
				result = false;
			}
			if (!read_from_file(file_name)) {
				std::cout << "Error! Read data from " << file_name.c_str() << std::endl;
				result = false;
    		}
			break;
		case 1: // only read
			if (!read_from_file(file_name)) {
				std::cout << "Error! Read data from " << file_name.c_str() << std::endl;
				result = false;
    		}
			break;
	}
    return result;
}