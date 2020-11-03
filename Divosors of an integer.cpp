// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW6 Q4 
// Program: Divisors 
// Description: Prints all divisors of number 

#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);

int main()
{
	int num;

	cout << "This program prints the divisors of an integer you enter!" << endl;
	cout << "Big-O(sqrt)" << endl;
	cout << "Enter a positive integer >= 2: ";
	cin >> num;
	while (cin.fail()) {
		cout << "You entered an illegal character please enter a positive integer >= 2: ";
		cin.clear();
		cin.ignore(999, '\n');
		cin >> num;
	}

	while (num < 2) {
		cout << "You entered " << num << " please enter a number >= 2: ";
		cin >> num;
	}

	printDivisors(num);

	return 0;
}
void printDivisors(int num) {
	
	int index;

	index = 1;
	while (index < sqrt(num)) {
		if (num % index == 0) {
			cout << index << " ";
		}
		index++;
	}
	int counter;

	counter = sqrt(num);
	index = 1;
	while (index <= sqrt(num)) {
		if (num % counter == 0) {
			cout << (num / counter) << " ";
		}
		index++;
		counter--;
	}
}