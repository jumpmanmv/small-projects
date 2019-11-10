/* 
	bubble_sort.hpp

	================================================================

	Sorts elements of a container in ascending order by using the bubble sort algorithm.
	
	Bubble sort relies on continuously comparing 2 adjacent elements and
	swapping them if their relative order is wrong.
	In this implementation we use an optimized version that finishes when it detects that the order
	is already correct.
	This algorithm works on arrays, vectors and other containers as long as they
	have the [] operator and their elements can be compared. The algorithm works on integers, doubles,
	chars, strings and other data types as long as they can be compared.

	=================================================================
	
	Time complexity: O(n^2)
	Space complexity: O(1)
	Stability: Stable

*/
template <typename T>
void bubble_sort(T &container, int N)
{
	for (int i = 0; i < N-1; i++) {
		bool is_finished = true;
		for (int j = 0; j < N-i-1; j++) {	// N-i-1 because in each loop the last element will be in the correct position
			if (container[j] > container[j+1]) {
				auto temp = container[j+1];
				container[j+1] = container[j];
				container[j] = temp;
				is_finished = false;
			}
		}
		if (is_finished) break;
	}
	return;
}
