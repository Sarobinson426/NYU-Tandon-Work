// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW6 Q1
// Program: Pine Tree
// Description: Write	a	program	that,	prints	a	‘pine	tree’	consisting	of	triangles	of	increasing	sizes,	filled	
// with	a	character(eg.‘* ’ or ’ + ’ or ‘$’	etc).
// Your	program	should	interact with	the	user	to	read	the	number	of	triangles	in	the	treeand
// the	character	filling	the	tree.

#include <iostream> 
using namespace std;

void print_shifted_triangle(int n, int m, char symbol);
void print_pine_tree(int n, char symbol);

int main() 
{
	int branches;
	char leaf;

	cout << "Enter the size of the pine tree (positive integer): ";
	cin >> branches;
	cout << "Enter a symbol to make your pine tree out of: ";
	cin >> leaf;

	print_pine_tree(branches, leaf);

	return 0;
}

void print_shifted_triangle(int n, int m, char symbol) {

	int branch_count, num_leaves, print_space, num_space, print_leaf;

	for (branch_count = 1, num_space = (m - 1), num_leaves = 1; 
		branch_count <= n; 
		branch_count++, num_space--, num_leaves += 2) {
		for (print_space = 1; print_space <= (num_space); print_space++) {
			cout << " ";
		}
		for (print_leaf = 1; print_leaf <= num_leaves; print_leaf++) {
			cout << symbol;
		}
		cout << endl;
	}
}

void print_pine_tree(int n, char symbol) {

	int print, index, set_size;

	set_size = n;
	index = 2;
	while (index <= n) {
		print_shifted_triangle(index, set_size, symbol);
		index++;
	}
	}

