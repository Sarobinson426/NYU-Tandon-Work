// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW9 Q1
// Program: Anagrams 
// Input: two strings are input 
// Output: true/false whether two strings are anagrams or not
// Description: 

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int ALPHABET = 26;

string input_and_initialization();

bool string_length_comp(string str1, string str2, int &str1_l, int &str2_l);
// measures length of two strings and output true/false if same length

bool is_anagram(int a1[], int a2[], string s1, string s2);
// compares char count of each char in a string between two strings 
// returns true if same contents false otherwise 

int main()
{
	string str1, str2;
	int str1_count, str2_count;

	cout << "This program will tell you whether a sentence or word is an anagram" << endl;
	cout << "Watch your spaces when entering your words / sentences!" << endl;
	str1 = input_and_initialization();
	str2 = input_and_initialization();

	int* str1_arr, * str2_arr;
	str1_arr = new int[ALPHABET]();
	str2_arr = new int[ALPHABET]();

	if (is_anagram(str1_arr, str2_arr, str1, str2) == true && string_length_comp(str1, str2, str1_count, str2_count) == true) {
		cout << "Is anagram!";
	}
	else {
		cout << "Is not an anagram!";
	}
	
	//for (int index = 0; index < ALPHABET; index++) {
	//	cout << "Index: " << static_cast<char>(index + 97) << " " << str1_arr[index] << "Index: " << static_cast<char>(index + 97) << " " << str2_arr[index] << endl;
	//}

	return 0;
}
string input_and_initialization() {
	string str;

	cout << "Enter a string: ";
	getline(cin, str);

	return str;
}
bool string_length_comp(string str1, string str2, int& str1_l, int& str2_l) {

	str1_l = str1.length();
	str2_l = str2.length();

	if (str1_l != str2_l) {
		return false;
	}

	return true;
}
bool is_anagram(int a1[], int a2[], string s1, string s2) {

	for (int index = 0; s1[index] && s2[index]; index++) {
		if ((s1[index]) >= 'A' && (s1[index]) <= 'Z') {
			a1[s1[index] + 32 - 97]++;
		}
		if ((s1[index]) >= 'a' && (s1[index]) <= 'z') {
			a1[s1[index] - 97]++;
		}
		if ((s2[index]) >= 'A' && (s2[index]) <= 'Z') {
			a2[s2[index] + 32 - 97]++;
		}
		if ((s2[index]) >= 'a' && (s2[index]) <= 'z') {
			a2[s2[index] - 97]++;
		}
	}

	for (int index = 0; index <= ALPHABET; index++) {
		if (a1[index] != a2[index]) {
			return false;
		}
	}

	return true;
}