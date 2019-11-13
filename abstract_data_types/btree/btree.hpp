/*
	btree.hpp
	created on 12/11/2019
	=================================================================

	Implementation of a binary tree (Btree). Uses the Node struct.
	Each node holds an integer value, but this can easily be changed to floats/doubles or even strings.

	=================================================================

*/
#include <iostream> // necessary for printing

struct Node
{
	int data;
	Node *left;
	Node *right;
};


class Btree 
{
public:
	Btree(); // constructor
	~Btree(); // destructor

	bool is_empty();
	int height();	
	void insert(int key); // inserts element with value "key" into the tree
	bool search(int key); // returns true if "key" value exists within the tree, false it not
	void remove(int key); // removes element with value "key" from the tree
	void destroy_tree(); // completely destroys tree (by deleting the respective pointers), useful for the destructor
	
	void print_preorder(); // prints the tree elements in preorder traversal
	void print_inorder(); // prints the tree elements in inorder traversal
	void print_postorder(); // prints the tree elements in postorder traversal

private:
	Node *root;

	// the below methods are auxiliary for the public methods
	int height(Node *n);
	void insert(int key, Node *&n);
	bool search(int key, Node *n);
	void remove(int key, Node *&n, Node *&parent);
	void destroy_tree(Node *&n);
	
	void print_preorder(Node *n);
	void print_inorder(Node *n);
	void print_postorder(Node *n);
};


// PUBLIC METHODS BEGIN HERE

Btree::Btree() { root = nullptr; }

Btree::~Btree() { destroy_tree(); }

bool Btree::is_empty() { return (root == nullptr); }

int Btree::height()
{
	if (is_empty()) return -1;
	else return 1 + std::max(height(root->left), height(root->right));
}

void Btree::insert(int key) 
{
	if (root == nullptr) {
		root = new Node;
		root->data = key;
		root->left = nullptr;
		root->right = nullptr;
	}
	else insert(key, root);
	return;
}

bool Btree::search(int key)
{
	if (is_empty()) return false;
	else return search(key, root);
}

void Btree::remove(int key)
{
	if (is_empty())	return;
	else if (key == root->data) destroy_tree(); // delete everything
	else remove(key, root, root);
	return;
}


void Btree::destroy_tree()
{
	destroy_tree(root);
	return;
}

void Btree::print_preorder()
{	
	std::cout << "Preorder Traversal: ";
	if (is_empty())	return;
	else {
		std::cout << root->data << " ";
		print_preorder(root->left);
		print_preorder(root->right);
	}
	std::cout << '\n';
	return;
}

void Btree::print_inorder()
{
	std::cout << "Inorder Traversal: ";
	if (is_empty())	return;
	else {
		print_inorder(root->left);
		std::cout << root->data << " ";
		print_inorder(root->right);
	}
	std::cout << '\n';
	return;
}

void Btree::print_postorder()
{
	std::cout << "Postorder Traversal: ";
	if (is_empty())	return;
	else {
		print_postorder(root->left);
		print_postorder(root->right);
		std::cout << root->data << " ";
	}
	std::cout << '\n';
	return;
}


// PRIVATE METHODS START HERE

int Btree::height(Node *n)
{
	if (n == nullptr) return 0;
	else return 1 + std::max(height(n->left), height(n->right));
}

void Btree::insert(int key, Node *&n)
{
	if (n == nullptr) {
		n = new Node;
		n->data = key;
		n->left = nullptr;
		n->right = nullptr;
	}
	else if (key < n->data) {
		insert(key, n->left);
	}
	else if (key > n->data) {
		insert(key, n->right);
	}
	return; // if key == n->data then do nothing
}

bool Btree::search(int key, Node *n)
{
	if (n == nullptr) return false;
	else if (key < n->data) {
		return search(key, n->left);
	}
	else if (key > n->data) {
		return search(key, n->right);
	}
	else {
		return true;
	}
}

void Btree::remove(int key, Node *&n, Node *&parent) 
{
	if (n == nullptr) return;
	else if (key < n->data) {
		remove(key, n->left, n);
	}
	else if (key > n->data) {
		remove(key, n->right, n);
	}
	else {
		if (n->left == nullptr && n->right == nullptr) {
			if (parent->left == n) {
				parent->left = nullptr;
				delete n;
			}
			else {
				parent->right = nullptr;
				delete n;
			}
		}
		else if (n->left == nullptr) {
			if (parent->left == n) {
				parent->left = n->right;
				delete n;
			}
			else {
				parent->right = n->right;
				delete n;
			}
		}
		else if (n->right == nullptr) {
			if (parent->left == n) {
				parent->left = n->left;
				delete n;
			}
			else {
				parent->right = n->left;
				delete n;
			}
		}
		else {
			if (parent->left == n) {
				parent->left = n->right;
				n->right->left = n->left;
				delete n;
			}
			else {
				parent->right = n->left;
				n->left->right = n->right;
				delete n;
			}
		}
	}
	return;
}

void Btree::destroy_tree(Node *&n)
{
	if (n == nullptr) return;
	else {
		destroy_tree(n->left);
		destroy_tree(n->right);
		n = nullptr;
	}
	return;
}

void Btree::print_preorder(Node *n) 
{
	if (n == nullptr) return;
	else {
		std::cout << n->data << " ";
		print_preorder(n->left);
		print_preorder(n->right);
	}
	return;
}

void Btree::print_inorder(Node *n)
{
	if (n == nullptr) return;
	else {
		print_inorder(n->left);
		std::cout << n->data << " ";
		print_inorder(n->right);
	}
	return;
}

void Btree::print_postorder(Node *n)
{
	if (n == nullptr) return;
	else {
		print_postorder(n->left);
		print_postorder(n->right);
		std::cout << n->data << " ";
	}
	return;
}
