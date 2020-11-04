// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW8 Q1
// Program: Format Name
// Input: First, middle, and last name
// Output: formatted full name
// Assumptoins: 

#include <iostream>
#include <string>
using namespace std;

void enter_and_format_name();

int main()
{
	enter_and_format_name();
	return 0;
}

void enter_and_format_name() {

	string first_name, middle_name, last_name;

	cout << "Please enter your full name (e.g. John Scott Doe): ";
	cin >> first_name >> middle_name >> last_name;

	cout << last_name << ", " << first_name << " " << middle_name[0] << ".";

}
