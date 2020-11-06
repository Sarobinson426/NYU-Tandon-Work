// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW10 Q2
// Program: Find Missing Numbers 
// Input: Input int by user
// Output: Output int arr (vector) 
// Description: User inputs numbers from an array and this program
// finds and prints the missing numbers in the array for the range 
// of the array

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> findMissing(vector<int> v);
vector<int> input_num();

int main() {
	vector<int>input_numbers, missin_num;

	input_numbers = input_num();
	for (vector<int>::iterator it = input_numbers.begin(); it != input_numbers.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	missin_num = findMissing(input_numbers);
	cout << "Missing Numbers: " << endl;
	for (vector<int>::iterator it = missin_num.begin(); it != missin_num.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}
vector<int> input_num() {
	vector<int> inputs;
	int user_nums, number_count, size_vect;
	bool last_num;
	cout << "This program takes in numbers from user and return missing numbers from that array range" << endl;
	cout << "Enter numbers into an array using numbers up to (-1 to exit): ";

	last_num = false;
	number_count = 0;
	while (last_num == false) {
		cin >> user_nums;
		if (user_nums <= -1) {
			last_num = true;
		}
		else {
			inputs.push_back(user_nums);
			number_count++;
		}
	}
	cout << "Size of array: " << inputs.size() << endl;
	return inputs;
}
vector<int> findMissing(vector<int> v) {
	vector<int> temp, missing_numbers;
	int max, min, range;

	max = min = v[0];
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
		if (*it > max) {
			max = *it;
		}
		if (*it < min) {
			min = *it;
		}
	}

	range = max - min;
	for (int i = 0; i <= range; i++) {
		temp.push_back(min);
		min++;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		for (vector<int>::iterator iit = temp.begin(); iit != temp.end(); iit++) {
			if (*it == *iit) {
				*iit = 0;
			}
		}
	}

	for (vector<int>::iterator it = temp.begin(); it != temp.end(); it++) {
		if (*it != 0) {
			missing_numbers.push_back(*it);
		}
	}
	
	cout << "Size of array: " << missing_numbers.size() << endl;
	return missing_numbers;
} 