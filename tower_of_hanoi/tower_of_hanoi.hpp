/* 
	tower_of_hanoi.hpp
	created on 8/11/2019
	
	================================================================

	Algorithm that solves the Tower of Hanoi puzzle.
	The Tower of Hanoi is an elegant mathematical puzzle. The game starts with all disks in peg A in ascending order
	from bottom to top.	The goal is to move all the disks from peg 'A' to peg 'C' moving 1 disk at a time.
	The player cannot place a bigger disk op top of a smaller disk.

	This solution utilizes recursion. In this case we solve the puzzle by typing the command that
	the player must follow (e.g "Move disk 1 from (peg) A to (peg) C")

	===============================================================

	Time complexity:  O(2^n - 1), where n is the initial number of disks.
	Space complexity: O(1)
*/

// N symbolizes the number of disks (numbered from the smallest "1" to the biggest "N")
#include <iostream>

void tower_of_hanoi(int N, char start, char end, char through)
{
	if (N == 1) {
		std::cout << "Move disk 1 from " << start << " to " << end << std::endl;
	}
	else {
		tower_of_hanoi(N-1, start, through, end);
		std::cout << "Move disk " << N << " from " << start << " to " << end << std::endl;
		tower_of_hanoi(N-1, through, end, start);
	}
}
