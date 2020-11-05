// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW9 Q1
// Program: Word Count Character Frequencies
// Input: string from the user any length
// Output: word count a list of characters with there associated frequencies
// Description: 

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int ALPHABET = 26;
typedef int* intPtr;

string input(int& arr_size);

void word_ch_counter(string str, int& ch_count);
// counts the characters and words in a string

void initialize_array(int a[]);
// initializes dynamic array to all 0's

void pop_freq_array(string str, int size_of_array);
// populates the dynamic frequency array with count of each character

int main()
{
	string str;
	int ch_count, arr_size;

	//user inputs a string 
	str = input(arr_size);

	//words are calculated using ' ' spaces to account for words 
	ch_count = 0;
	word_ch_counter(str, ch_count);

	pop_freq_array(str, arr_size);

	return 0;
}
string input(int& arr_size) {
	string str;

	cout << "Enter a sentence: ";
	getline(cin, str);

	arr_size = str.length();

	return str;
}
void word_ch_counter(string str, int& ch_count) {
	int word_count;

	word_count = 0;
	for (int index = 0; index <= str.length(); index++) {
		if (str[index] == ' ' || str[index] == '\0') {
			word_count++;
		}
		ch_count++;
	}

	cout << "The sentence has " << word_count << " words in it with the following character frequencies: " << endl;
}
void initialize_array(int a[]) {

	for (int index = 0; index < 26; index++) {
		a[index] = 0;
	}
}
void pop_freq_array(string str, int size_of_array) {
	intPtr freq_array;

	freq_array = new int[ALPHABET];
	initialize_array(freq_array);
	for (int index = 0; index < size_of_array; index++) {
		if (static_cast<int>(str[index]) >= 65 && static_cast<int>(str[index]) <= 90) {
			freq_array[str[index] + 32 - 97]++;
		}
		if (static_cast<int>(str[index]) >= 97 && static_cast<int>(str[index]) <= 122) {
			freq_array[str[index] - 97]++;
		}
	}

	char ch_index = 'a';
	for (int index = 0; index <= ALPHABET; index++) {
		if (freq_array[index] > 0) {
			cout << ch_index << "\t" << freq_array[index] << endl;
		}
		ch_index++;
	}

	delete[] freq_array;
}