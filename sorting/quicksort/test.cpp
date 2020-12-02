#include "quicksort.hpp"
#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<int> v;
	int k;
	std::cout << "Enter vector size: ";
	std::cin >> k;
	std::cout << "Enter elements: ";
	int data;
	for (int i = 0; i < k; i++) {
		std::cin >> data;
		v.push_back(data);
	}
	int n = v.size();

	std::cout << "Before sorting: " << '\n';
	for (int i = 0; i < n; i++) {
		std::cout << v[i] << " ";
	}	
	quicksort(v, n);
	std::cout << '\n' << "After sorting: " << '\n';
	for (int i = 0; i < n; i++) {
		std::cout << v[i] << " ";
	}
	return 0;
}
