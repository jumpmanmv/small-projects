/*
 *	selection_sort.hpp
 *
 *	=================================================================
 *
 *	Sorts elements of a container in ascending order using the selection sort algorithm.
 *
 *	Selection sort finds the correct spot for the minimum element one at a time, starting with the first
 *	and finishing with the last.
 *
 *	This function works on arrays, vectors, and other containers as long as they have the [] operator overloaded
 *	and their elements can be compared.
 *	This function works on integers, doubles, chars, string, and other data types as long as they can be compared
 *  with the < and > operators.
 *	
 *	=================================================================
 *
 *	Time complexity: O(n^2)
 *	Space complexity: O(1)
 *	Stability: Not stable by default, but can be made by pushing the minimum element to the front each time instead of swapping
 *	the elements. This function is not stable.
 */

template <typename T>
void selection_sort(T& container, int N)
{
	for (int i = 0; i < N-1; i++) {
		int min_index = i; // index of the smallest element in the current loop
		for (int j = i+1; j < N; j++) {
			if (container[j] < container[min_index]) {
				min_index = j;
			}
		}
		auto temp = container[i];
		container[i] = container[min_index];
		container[min_index] = temp;
	}
	return;
}
