/*
 *	insertion_sort.hpp
 *
 *	=================================================================
 *
 *	Sorts elements of a container in ascending order using the insertion sort algorithm.
 *	
 *	Insertion sort works by utilizing a sorted sub-container that starts from the first 2 elements sorted and slowly
 *	adds new elements by finding their correct position on the already sorted sub-container.
 *
 *	This function works on arrays, vectors and other containers as long as they have the [] operator overloaded
 *  and their elements can be compared.
 *  The function works on integers, doubles, chars, strings and other data types as long as they can be compared
 *  with the < and > operators.
 *	
 *	=================================================================
 *
 *	Time complexity: O(n^2)
 *	Space complexity: O(1)
 *	Stability: Stable
 */

template <typename T>
void insertion_sort(T &container, int N)
{
	for (int i = 1; i < N; i++) {
		for (int j = i; j > 0; j--) {
			if (container[j] < container[j-1]) {
				auto temp = container[j-1];
				container[j-1] = container[j];
				container[j] = temp;
			}
			else break;
		}
	}
	return;
}
