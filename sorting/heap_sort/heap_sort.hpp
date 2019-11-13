/*
	heap_sort.hpp

	=================================================================

	Sorts elements of a container in ascending order. Uses the heap sort algorithm.
	Heap sort is an improved version of the selection sort. Efficiency is increased by sorting the remaining elements
	in a max heap each time after removing an element.

	A max heap is an almost complete binary tree where the value of the parent is greater than
	the value of their children. We can simulate the max heap with the container we are using where a child cont[i] has
	parent cont[(i-1)/2] assuming cont[0] is the first element in the container.

	This algorithm works on arrays, vectors and other containers as long as they
    have the [] operator and their elements can be compared. The algorithm works on integers, doubles,
    chars, strings and other data types as long as they can be compared (with the < and > symbols).

	=================================================================

	Time Complexity: O(nlogn), Θ(nlogn)
	Space Complexity: O(1)
	Stability: Not stable.

*/

// heapify corrects the heap in order to keep the max heap properties
template <typename T>
void heapify(T &cont, int end) // end is the index for the current last element in the heap.
{
	for(int i = end; i > 0; i--) { // if a child has greater value than the parent, then swap them
		if (cont[i] > cont[(i-1)/2]) {
			auto tempo = cont[(i-1)/2];
			cont[(i-1)/2] = cont[i];
			cont[i] = tempo;
		}
	}
	return;
}

template <typename T>
void heap_sort(T &cont, int N) // N is the number of elements in the container
{
	// in iteration "i" the first i elements of the container are reserved for the heap
	// while the last elements are sorted in ascending order
	for (int i = N-1; i > 0; i--) {
		heapify(cont, i);
		auto temp = cont[0];
		cont[0] = cont[i];
		cont[i] = temp;
	}
	return;
}

