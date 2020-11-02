// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW5 Q1
// Program: Enter and Multiply
// Description: Write a program that reads a positive integer n from the user and prints out a 'n x n' (n by n)
// multiplication table.The columns should be spaced by a tab.

#include <iostream>
using namespace std;

void input(int& input_number);
void print_mult_table(const int& input_number);

int main()
{
	int input_mtable;

	input(input_mtable);
	print_mult_table(input_mtable);

	return 0;
}

void input(int& input_number) {
	cout << "This program prints a multiplication table e.g. if enter 10 then all multiplications from 1 * 1 to 10 * 10" << endl;
	cout << "Enter a positive integer: ";
	cin >> input_number;
}

void print_mult_table(const int& input_number) {
	int line_count, row, multiplicant;

	for (line_count = 1, multiplicant = 1; line_count <= input_number; line_count++, multiplicant++) {
		//each row multiplied by the left most column first number
		for (row = 1; row <= input_number; row++) {
			cout << row * multiplicant << "\t";
		}
		cout << endl;
	}
}
