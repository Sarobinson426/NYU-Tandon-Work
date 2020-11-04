// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW8 Q1
// Program: Palindrome
// Description: User enters a string and the program 
// returns a bool value which is used to tell user if 
// string is a palindrome or not

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string input();
bool isPalindrome(string str);
	//This function is given a string str containing a word, 
	//and returns true if and only if str is a palindrome

int main()
{
	string palindrome_result;

	palindrome_result = input();
	if (isPalindrome(palindrome_result) == true) {
		cout << palindrome_result << " is a Palindrome" << endl;
	}
	else {
		cout << "Not a Palindrome!" << endl;
	}
	
	return 0;
}
string input() {
	string user_string;

	cout << "Please enter a string: ";
	cin >> user_string;
	
	return user_string;
}
bool isPalindrome(string str) {

	for (int reverse = str.length() - 1, forward = 0; forward <= str.length() - 1; reverse--, forward++) {
		if (str[forward] == str[reverse]) {
			return true;
		}
		else {
			return false;
		}
	}
}