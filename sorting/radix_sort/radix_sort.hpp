/*
 *	radix_sort.hpp
 *
 *	==================================================================
 *
 *	Sorts elements of a container with size n in ascending order, using the radix sort algorithm.
 *
 *	Radix sort is a non-comparative sorting algorithm. It works by using the count_sort subroutine on each digit position.
 *	count_sort sorts the elements by putting them into buckets depending on their digit value at a certain position.
 *	Radix sort starts from the LSD (least significant digit) and ends with the MSD digit (most significant digit) of the
 *	largest number.
 *
 *	Radix sort can be used for every base, but in this case we assume that the numbers are in base 10.
 *	The algorithm works on containers that have the [] operator overloaded and their elements can be compared with
 *  the < and > operators.
 *	The elements must be non-negative integers.
 *
 *	==================================================================
 *
 *	Time complexity: O(d*(n+k)), where n is the number of elements, k is the base (in this case 10), and d is
 *	the number of digits of the largest element in the container.
 *	Space complexity: O(n+k), where n is the number of elements, and k is the base (in this case 10)
 *	Stability: Stable
 */

long long pow(int base, int expo)
// basic power function, used only for positive integer base and positive integer exponent
{
	if (expo == 0) return 1;
	else if (expo == 1) return base;
	else return base*pow(base, expo-1);
}


template <typename T>
int get_max(const T &cont, int n)
// returns the max value of a container
{
	int max = cont[0];
	for (int i = 1; i < n; i++) {
		if (cont[i] > max) max = cont[i];
	}
	return max;
}

int get_digit(int num, int pos)
// gets value of digit at position "pos" for the number "num"
// the LSD is considered to be at position 0, the next at position 1, etc.
// If a number doesn't have a digit at position pos, 0 is returned (e.g 7 at position 1).
{
	for (int i = 0; i < pos; i++) num /= 10;
	return num % 10;
}

template <typename T>
void count_sort(T &cont, int n, int pos) 
{
	int digit[10] = {0};
	for (int i = 0; i < n; i++) { // digit[] tracks the number of occurences for each digit in a position
		digit[get_digit(cont[i], pos)]++;
	}
	for (int i = 1; i <= 9; i++) {
		digit[i] += digit[i-1]; // accumulate
	}
	int temp_arr[n] = {0};
	for (int j = n-1; j >= 0; j--) {
		int d = get_digit(cont[j], pos);
		temp_arr[digit[d]-1] = cont[j];
		digit[d]--;
	}

	for (int i = 0; i < n; i++) cont[i] = temp_arr[i];
	return;

}

template <typename T>
void radix_sort(T &cont, int n)
{
	// count_sort one time for each digit (up to the MSD of the largest element)
	for (int i = 0; pow(10, i) <= get_max(cont, n); i++) {
		count_sort(cont, n, i);
	}
	return;
}
