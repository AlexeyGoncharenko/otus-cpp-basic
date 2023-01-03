#include <iostream>
#include <cstdlib>
int gcd(int,int);

int main(int argc, char* argv[]){
    int a, b, result;
    if (argc<3){
        std::cout << "Greatest Common Divisor (GCD) function" << std::endl;
        std::cout << "Input a: "; std::cin>>a;
        std::cout << "Input b: "; std::cin>>b;
    }else{
        a = std::atoi(argv[1]);
        b = std::atoi(argv[2]);
    }
    result = gcd(a, b);
    if (result == -1) {
        std::cerr << "Incorrect input data. Condition a > b > 0. \tTry again" << std::endl;
        return result;
    }
    else {
        std::cout << "Greatest Common Divisor for (a, b) is " << result << std::endl;
    }
    return 0;
}

/// @brief  Greatest Common Divisor (GCD) function
///         Uses Euclidean Algorithm - https://en.wikipedia.org/wiki/Euclidean_algorithm
/// @return GCD result
int gcd(int a, int b){
    int q, i, r = 1;
    if (a && b > 0){
        while(r != 0){
            for(i = 1; i * b <= a; i++){}
            q = i == 1 ? i : --i;
            r = std::abs(a - (b * q));     
            a = b;
            b = r > 0 ? r : b;
        }
    } else {
        return -1;
    }
    return b;
}