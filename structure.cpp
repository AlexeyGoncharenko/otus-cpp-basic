#include "netpbm.h"

#include <fstream>
#include <iostream>
#include <string>

namespace motivation_1 {

	// in - input parameter
	// out - output parameter
	// in/out - input/output parameter
	void get_user_info(std::string &name, std::string &surname, int &age) {
		std::cout << "Hello!" << std::endl;

		std::cout << "Enter your name:" << std::endl;
		std::cin >> name;

		std::cout << "Enter your surname:" << std::endl;
		std::cin >> surname;

		std::cout << "Enter your age:" << std::endl;
		std::cin >> age;
	}

	void example() {
		std::string name;
		std::string surname;
		int age;

		get_user_info(name, surname, age);

		if (age < 16) {
			std::cout << "Access denied!" << std::endl;
		} else if (age < 30) {
			std::cout << "Hello, " << name << std::endl;
		} else {
			std::cout << "Hello, " << name << " " << surname << std::endl;
		}
	}

} // motivation_1

namespace motivation_2 {

	void example_simple() {

		std::ofstream output("image_simple.pbm");
		if (!output.is_open()) {
			std::cerr << "Failed to open file image.pbm" << std::endl;
			return;
		}
		const int width = 10;
		const int height = 10;

		graphics::write_header(output, width, height);

		for (int row = 0; row < height; ++row) {
			for (int col = 0; col < width; ++col) {
				if (row == col) {
					graphics::write_pixel(output, 0, 112, 0);
				} else {
					graphics::write_pixel(output, 112, 112, 112);
				}
			}
		}
	}

	void example_medium() {

		const int width = 10;
		const int height = 10;
		char image[width * height] = {};

		graphics::clear(image, width, height);

		for (int row = 0; row < height; ++row) {
			for (int col = 0; col < width; ++col) {
				if (row == col) {
					graphics::put_pixel(image, width, height, 255, row, col);
				}
			}
		}

		std::ofstream output("image_medium.pbm");
		if (!output.is_open()) {
			std::cerr << "Failed to open file image.pbm" << std::endl;
			return;
		}
		graphics::dump_to_file(output, image, width, height);
	}

} // motivation_2

namespace structures {

	struct Person {
		std::string name;
		std::string surname;
		int age;
	};

	// std::tuple<std::string, std::string, int> get_user_info_2() {
	// 	return std::make_tuple("Name", "Surname", 42);
	// }

	// void func() {
	// 	std::tuple<std::string, std::string, int> t = get_user_info_2();

	// 	auto [name, surname, age] = get_user_info_2();
	// 	std::cout << name;
	// }

	Person get_user_info() {
		Person person;

		std::cout << "Hello!" << std::endl;

		std::cout << "Enter your name:" << std::endl;
		std::cin >> person.name;

		std::cout << "Enter your surname:" << std::endl;
		std::cin >> person.surname;

		std::cout << "Enter your age:" << std::endl;
		std::cin >> person.age;

		return person;
	}

	void example1() {
		Person person = get_user_info();

		if (person.age < 16) {
			std::cout << "Access denied!" << std::endl;
		} else if (person.age < 30) {
			std::cout << "Hello, " << person.name << std::endl;
		} else {
			std::cout << "Hello, " << person.name << " " << person.surname << std::endl;
		}
	}

	// struct Image {
	// 	char* buffer;
	// 	int width;
	// 	int height;
	// };

	void example2() {
		const int width = 50;
		const int height = 50;
		char buffer[width * height];

		graphics::Image image{
			buffer,
			width,
			height
		};
		graphics::clear(image);

		for (int row = 0; row < image.height; ++row) {
			for (int col = 0; col < image.width; ++col) {
				if (row == col) {
					graphics::put_pixel(image, 255, row, col);
				}
			}
		}

		std::ofstream output("image_medium_2.pbm");
		if (!output.is_open()) {
			std::cerr << "Failed to open file image.pbm" << std::endl;
			return;
		}
		graphics::dump_to_file(output, image);

	}

} // namespace structures

	struct my_person{
		std::string firstname;
		std::string secondname;
		int age;
	};

	std::ostream &operator<<(std::ostream &os, const my_person &person) {
		os << person.firstname << ' ' << person.secondname << ' ' << person.age;
		return os;
	}

int main() {

	// // :: - namespace
	// // . - member access
	// // -> - member access for pointers	

	motivation_1::example();
	motivation_2::example_simple();
	motivation_2::example_medium();
	structures::example1();
	structures::example2();

	return 0;
}