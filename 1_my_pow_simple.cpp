#include <iostream>
#include <iomanip>

double power(double base, int exp) {
	double result = 1.0;
	if(fabs(0 - base) <= std::numeric_limits<double>::epsilon()){
		return 0.0;
	}
	else if(exp == 0){
		return 1.0;
	}
	else {
		for (int i = 0; i < std::abs(exp); ++i) {
			result *= base;
		}
		return exp > 0 ? result : 1.0/result;
	}
}

int main() {
	double base = 0.0;
	int exp = 0;
	std::string buffer{""};

	std::cout << "Enter base: ";
	std::cin >> buffer;
	base = std::atoi(buffer.c_str());
	
	std::cout << "Enter exp: ";
	std::cin >> buffer;
	exp = std::atoi(buffer.c_str());
	
	std::cout << std::setprecision(5) << "pow(" << base << ", " << exp << ") = " << power(base, exp) << std::endl;
	return 0;
}