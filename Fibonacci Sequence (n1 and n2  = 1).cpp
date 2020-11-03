// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW6 Q1
// Program: Fibonacci Sequence
// Description: The	Fibonacci	numbers sequence, Fn,	is defined	as	follows:
// F1 is	1, F2 is	1, and Fn = Fn - 1 + Fn - 2 for	n = 3, 4, 5, ...
// In	other	words, each	number	is	the	sum	of	the	previous	two	numbers.The	first	10	numbers
// in	Fibonacci	sequence	are : 1, 1, 2, 3, 5, 8, 13, 21, 34, 55


#include <iostream>
using namespace std;

int fibonacci(int n);

int main()
{
	int fib_sequence, result;

	cout << "Print fibonacci sequence where the n1 and n2 are both 1" << endl;
	cout << "Enter an integer to index corresponding Fibonacci value: ";
	cin >> fib_sequence;

	result = fibonacci(fib_sequence);
	cout << "\nThe " << fib_sequence << " in the fibonacci sequence is: " << result << endl;

	return 0;
}

int fibonacci(int n) {
	int index, fib1, fib2, next_fib;

	fib1 = 1;
	fib2 = 1;
	next_fib = 0;
	index = 3;
	cout << fib1 << " " << fib2 << " ";
	if (n == 1 || n == 2) {
		cout << fib1;
	}
	if (n >= 3) {
		while (index <= (n)) {
			next_fib = fib1 + fib2;
			fib1 = fib2;
			fib2 = next_fib;

			cout << next_fib << " ";

			index++;
		}
		return next_fib;
	}
}