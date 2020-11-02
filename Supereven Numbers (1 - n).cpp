// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW4 Q6
// Program: Supereven
// Description: Write a program	that asks the user to input	a positive integer n, and print	all	of	the	numbers	
// from 1 to n that have more even digits than odd	digits.

#include <iostream>
using namespace std;

void input(int& user_num);
void print_super_even_numbers(const int& user_num);

int main()
{
	int user_num, manipulated_number, running_count, even_tally = 0, odd_tally = 0, tally_number = 0;

	input(user_num);
	print_super_even_numbers(user_num);
	
	return 0;
}

void input(int& user_num) {
	cout << "This program prints only the numbers with more\nevens in them from zero to the number you input!" << endl;
	cout << "e.g. 24 would print but not 25" << endl;

	cout << "Please enter a number: ";
	cin >> user_num;
}

void print_super_even_numbers(const int& user_num) {
	int manipulated_number, running_count, even_tally = 0, odd_tally = 0, tally_number = 0;

	running_count = 0;
	//count from 1 to to user_num
	while (running_count <= user_num) {
		//count number of even numbers in number being counted
		odd_tally = 0;
		even_tally = 0;
		manipulated_number = running_count;
		while (manipulated_number != 0) {
			//remove each number from counted number
			tally_number = manipulated_number % 10;
			//tally number as even or odd
			if ((tally_number % 2) == 0) {
				++even_tally;
			}
			else if ((tally_number % 2) != 0) {
				++odd_tally;
			}
			manipulated_number = manipulated_number / 10;
			//testing
			//cout << "even tally inside second while: " << even_tally << endl;
			//cout << "odd tally inside second while: " << odd_tally << endl;
		}
		//print running_count if has more even than odd numbers

		//testing
		//cout << "running number: " << running_count << endl;
		//cout << "even tally: " << even_tally << endl;
		//cout << "odd tally: " << odd_tally << endl;
		//cout << "\n\n";
		if (even_tally > odd_tally) {
			cout << "Even > Odd in this number: " << running_count << endl;
		}
		running_count++;
	}
}