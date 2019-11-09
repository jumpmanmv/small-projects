#include "greatest_common_divisor.hpp"
#include <iostream>

int main() 
{
	long long a = 1; long long b = 1;
	std::cout << "Enter first number: ";
	std::cin >> a;
	std::cout << "Enter second number: ";
	std::cin >> b;
	std::cout << "The gcd of " << a << " and " << b << " is " << gcd(a, b) << std::endl;
	return 0;
}
