#include "insertion_sort.hpp"
#include <iostream>
#include <vector>
#include <string>

int main()
{
 	// int arr[] = {64, 34, 25, 12, 22, 11, 90};
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
	insertion_sort(v, n);
	std::cout << '\n' << "After sorting: " << '\n';
	for (int i = 0; i < n; i++) {
		std::cout << v[i] << " ";
	}
	return 0;
}
