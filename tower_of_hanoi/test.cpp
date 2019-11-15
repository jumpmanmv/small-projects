#include "tower_of_hanoi.hpp"
#include <iostream>

int main()
{
	int N;
	std::cout << "Select number of disks: ";
	std::cin >> N;
	std::cout << "The solution of the Tower of Hanoi is as follows: " << '\n';
	tower_of_hanoi(N, 'A', 'C', 'B');
	return 0;
}
