// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW4 Q3
// Program: Decimal to Binary
// Description: Write a program that reads from the user a positive integer (in a decimal representation), and
// prints its binary (base 2) representation.

#include <iostream>
using namespace std;

void print_binary_number(int deci_number);

int main()
{
	int deci_num;

	cout << "Please enter a number: "; 
	cin >> deci_num;

	print_binary_number(deci_num);

	return 0;
}

void print_binary_number(int deci_number) {
	int binary_dig, binary_base, position;

	binary_base = 0;
	position = 1;
	while (deci_number != 0) {
		binary_dig = (deci_number % 2);
		binary_base = binary_base + binary_dig * position;
		deci_number = deci_number / 2;
		position = position * 10;
	}

	cout << binary_base << endl;
}