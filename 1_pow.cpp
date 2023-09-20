// OTUS C++ Basic course
// pow function example

#include <cfloat>
#include <cmath>
#include <iostream>
#include <limits>
#include <iomanip>

// Write pow function code below
double pow(double a, int b) {
	double result = 1.0;
	for (int i = 0; i < abs(b); ++i) {
		result *= a;
	}
	return b > 0 ? result : 1.0/result;
}

// compare if two double are close enougth and can be interpteted as equal
bool is_close(double a, double b) {
	if (std::isinf(a) && std::isinf(b)) {
		return true;
	}
	if (std::isnan(a) && std::isnan(b)) {
		return true;
	}
	return std::fabs(a - b) < std::numeric_limits<double>::epsilon() * std::max(1.0, std::max(std::fabs(a), std::fabs(b)));
}

// Test compares results of pow function provided by programmer with std::pow
bool test_pow(double base, int exp) {
	std::cout << std::setprecision(10) << "Testing pow(" << base << ", " << exp << ")\t";
	double expected = std::pow(base, exp);
	double actual = pow(base, exp);
	std::cout << "Expected=" << expected << " Actual=" << actual << std::endl;
	if (is_close(expected, actual)) {
		std::cout << "OK\n";
		return true;
	} else {
		std::cout << "FAIL\n";
		return false;
	}
}

int main() {
	bool all_success = true;

	all_success &= test_pow(2.0, 3);
	all_success &= test_pow(2.0, -3);
	all_success &= test_pow(1.0, 1);
	all_success &= test_pow(5.0, 0);
	all_success &= test_pow(-5.0, 2);
	all_success &= test_pow(-5.0, 3);
	all_success &= test_pow(0.0, 2);
	all_success &= test_pow(1.1e+5, 10);
	all_success &= test_pow(1e-5, 10);
	all_success &= test_pow(INFINITY, 2);
	all_success &= test_pow(NAN, 2);

	return all_success;
}