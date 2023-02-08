#include "compilation.h"
#include <iostream>

#define MY_SUPER_CONSTANT 42
#define MY_SUPER_MAX(a, b) ((a<b)?b:a)
#define NAME_AND_VALUE(variable) (std::cout << "variable = " << variable << std::endl)

void some_function(int) {	
}

void some_other_function(float) {
}

int main() {
	MY_SUPER_CONSTANT;

	some_function(MY_SUPER_CONSTANT);
	int i=3,j=++i,k=++i;

	some_other_function(34.f);
	printf("k=%d,j=%d,i=%d",k,j,i);
	int max = MY_SUPER_MAX(42, 45);
	//int max2 = MY_SUPER_MAX(1, "hello!"); // Ooops

	NAME_AND_VALUE(max);
	
	return 0;
}