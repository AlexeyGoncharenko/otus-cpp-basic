#include <iostream>
#include <iomanip>
double power(double,int);
int main() {
	double	base = 0.0;
	int exp = 0;
	std::cout << "Enter base: ";
	std::cin >> base;
	std::cout << "Enter exp: ";
	std::cin >> exp;
	std::cout << std::setprecision(10) << "pow(" << base << ", " << exp << ") = " << power(base, exp) << std::endl;
	return 0;
}
double power(double base, int exp) {
	double result = 1.0;
	if(fabs(0 - base) <= std::numeric_limits<double>::epsilon()){
		return 0.0;
	}
	else if(exp == 0){
		return 1.0;
	}
	else {
		for (unsigned int i = 0; i < abs(exp); ++i) {
			result *= base;
		}
		return exp > 0 ? result : 1.0/result;
	}
}