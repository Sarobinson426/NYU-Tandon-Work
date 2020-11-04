// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW8 Q1
// Program: String 'x' out numbers
// Input: String -text and numbers
// Output: String -converted to a string w/ x in place of numbers
// Assumptions:

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string x_text();

int main()
{
	string text;
	int index;

	text = x_text();
	cout << text << endl;
	
	return 0;
}
string x_text() {
	string text;

	cout << "Enter text: ";
	getline(cin, text);

	for (int index = 0; index < text.length(); index++) {
		if (static_cast<int>(text[index]) <= 57 && static_cast<int>(text[index]) >=48) {
			text[index] = 'x';
		}
	}

	return text;
}


