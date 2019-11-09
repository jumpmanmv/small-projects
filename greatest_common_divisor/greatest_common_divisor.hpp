/*  
	greatest_common_devisor.hpp
	created on 7/11/2019

	=================================================================================

	Euclid's algorithm that calculates the greatest common divisor [notation gcd] of 2 numbers a and b.
	The algorithm works on both integer and real numbers, but on real numbers the algorithm will likely not finish. while on integers a result is guaranteed.

	In this case we will restrict the numbers a and b to be integers.
	

	NOTE: the abs function is needed in the case where both a and b are negative numbers.
	If both a and b are 0, then the output of the algorithm is 0. This isn't correct, since the answer to that is usually undefined.
	=================================================================================

	TIME COMPLEXITY: upper limit is O(log2(n)) where n is min(a, b)
*/

#ifndef GREATEST_COMMON_DIVISOR_HPP
#define GREATEST_COMMON_DIVISOR_HPP

long long gcd(long long a, long long b)
{
	if (b == 0) {
		return (a >= 0) ? a : -a;
	}
	else return gcd(b, a % b);
}

#endif
