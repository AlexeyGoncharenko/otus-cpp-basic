// OTUS C++ basic course
// Recursive fibinacci numbers

#include <cstdlib>
#include <iostream>
#include <chrono>

// Recursive implementation eval nth fibanicci number
unsigned long fib_recur(unsigned long n) {
	if (n < 2) {
		return n;
	}
	return fib_recur(n - 1) + fib_recur(n - 2);
}

// Iterative implementation eval nth fibanicci number
void fib_iter(unsigned long n) {
	unsigned long long *fib_values = new unsigned long long[n];
	fib_values[0] = 0;
	fib_values[1] = 1;
	for (unsigned long i=2; i <= n; i++) {
		fib_values[i] = fib_values[i-1] + fib_values[i-2];
	}
	for (unsigned long i = 0; i <= n; i++) {
		std::cout << fib_values[i] << std::endl;
	}
}

int main(int argc, char *argv[]) {
	unsigned long n = 5;
	if (argc == 2) {
		long tmp = std::atol(argv[1]);
		if (tmp < 0) {
			std::cerr << "Only non-negative number allowed\n";
			return -1;
		}
		else {
			n = tmp;
		}
	}

	auto start_time = std::chrono::steady_clock::now();
	for (unsigned long i = 0; i <= n; ++i) {
			std::cout << fib_recur(i) << "\n";
	}
	auto end_time = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end_time - start_time;
	std::cout << "Elapsed time for recursive implementation fibonacci algorithm: " << elapsed_seconds.count() << "s.\n";

	start_time = std::chrono::steady_clock::now();
	fib_iter(n);
	end_time = std::chrono::steady_clock::now();
	elapsed_seconds = end_time - start_time;
	std::cout << "Elapsed time for iterative implementation fibonacci algorithm: " << elapsed_seconds.count() << "s.\n";

	return EXIT_SUCCESS;
}