#include "btree.hpp"
#include <iostream>

int main() {
	Btree t;
	t.insert(10);
	std::cout << "Current height: " << t.height() << '\n';
	t.insert(20);
	std::cout << "Current height: " << t.height() << '\n';
	t.insert(25);
	std::cout << "Current height: " << t.height() << '\n';
	t.insert(8);
	std::cout << "Current height: " << t.height() << '\n';
	t.insert(1);
	std::cout << "Current height: " << t.height() << '\n';
	
	t.print_preorder();
	t.print_inorder();
	t.print_postorder();

	t.remove(1);
	t.print_preorder();

	t.remove(8);
	t.print_preorder();
	t.remove(4);
	t.print_preorder();
	t.remove(10);
	t.print_preorder();
	std::cout << "Current height: " << t.height() << '\n';
	return 0;
}
