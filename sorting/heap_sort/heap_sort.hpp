/*
	heap_sort.hpp

	=================================================================

	Sorts elements of a container in ascending order. Uses the heap sort algorithm.
	Heap sort can be thought of as an improved version of the selection sort. Efficiency is increased by sorting
	the remaining element in a max heap each time after removing an element.

	A max heap is an almost complete binary tree where the value of the parent is greater than
	the value of their children. We can simulate the max heap with the container we are using where a "parent" cont[i] has
	"children" cont[2*i+1] (if they exist), assuming cont[0] is the first element in the container.

	This algorithm works on arrays, vectors and other containers as long as they
    have the [] operator and their elements can be compared. The algorithm works on integers, doubles,
    chars, strings and other data types as long as they can be compared (with the < and > symbols).

	=================================================================

	Time Complexity: O(nlogn), Θ(nlogn)
	Space Complexity: O(1)
	Stability: Not stable.

*/

// sift_down corrects the max heap after the first element is removed and placed in the sorted container
template <typename T>
void sift_down(T &cont, int parent, int end) // end is the index for the current last element in the heap
{	
	int cur_largest = parent;
	if ((2*parent+1 <= end) && (cont[2*parent+1] > cont[parent])) {
		cur_largest = 2*parent+1;
	}
	if ((2*parent+2 <= end) && (cont[2*parent+2] > cont[cur_largest])) {
		cur_largest = 2*parent+2;
	}
	if (cur_largest != parent) {
		auto tempo = cont[parent];
		cont[parent] = cont[cur_largest];
		cont[cur_largest] = tempo;
		sift_down(cont, cur_largest, end);
	}
	return;
}

// heapify is called once in order to build the max heap. The heap is built from the bottom up
template <typename T>
void heapify(T &cont, int end)
{
	for (int i = (end-1)/2; i >= 0; i--) {
		sift_down(cont, i, end);
	}
	return;
}

	
template <typename T>
void heap_sort(T &cont, int N) // N is the number of elements in the container
{
	heapify(cont, N-1);
	// in iteration "i" the first i elements of the container are reserved for the heap
	// while the last elements are sorted in ascending order
	for (int i = N-1; i > 0; i--) {
		auto temp = cont[0];
		cont[0] = cont[i];
		cont[i] = temp;
		sift_down(cont, 0, i-1);
	}
	return;
}
