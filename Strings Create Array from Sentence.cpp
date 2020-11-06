// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW10 Q1
// Program: Get words from Sentence
// Input: sentence from the user
// Output: words from the sentence in quotation marks e.g. "word"
// Description: User will be prompted to enter a sentence and a vector
// is used to find the words in the sentence and are output in main.

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string* 
createWordsArray(string sentence, int& outWordsArrSize);

int main() {
	string* out_string = NULL, input_sentence;
	int word_string_length = 0;

	cout << "Arr_size before: " << word_string_length << endl;
	cout << "Enter your favorite sentence: ";
	getline(cin, input_sentence);

	out_string = createWordsArray(input_sentence, word_string_length);

	cout << "\nArr_size after: " << word_string_length << endl;
	for (int index = 0; index < word_string_length; index++) {
		cout << "\"" << out_string[index] << "\"" << " ";
	}
	
	return 0;
}
string* 
createWordsArray(string sentence, int& outWordsArrSize) {
	string* word_arr = NULL, *new_word_arr = NULL, space = " ";
	int index, w_logic_size, w_phys_size;
	bool last_word;

	int end = 1, begin = 0, word_count = 0;
	while (end > 0) {
		end = sentence.find(space, begin);
		begin = end + 1;
		word_count++;
	}

	w_logic_size = 0;
	w_phys_size = 1;
	word_arr = new string[1];

	int word_length = 0;
	end = 0, begin = 0;
	last_word = false;
	while (last_word == false) {
		if (word_count == w_logic_size) {
			last_word = true;
		}
		else {
			if (w_logic_size == w_phys_size) {
				new_word_arr = new string[2 * w_phys_size];
				for (index = 0; index < w_logic_size; index++) {
					new_word_arr[index] = word_arr[index];
				}
				delete[] word_arr;
				word_arr = new_word_arr;
				w_phys_size *= 2;
			}
		end = sentence.find(space, begin);
		word_length = (end - begin);
		word_arr[w_logic_size] = sentence.substr(begin, word_length);
		begin = end + 1;
		w_logic_size++;
		}
	}

	outWordsArrSize = w_logic_size;

	return word_arr;
}