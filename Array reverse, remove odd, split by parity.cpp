// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW8 Q1
// Program: Arrays to sysrrA to ras to Aarrys 
// Description: A program that takes in an array

#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
// Reverses the array

void removeOdd(int arr[], int& arrSize);
// Removes odd in the string indices

void splitParity(int arr[], int arrSize);
//Splits the parity of the string indices

int main()
{
	int user_array[10], reverse_array[10], split_array[10], array_size, array_size2;

	cout << "This program takes an array reverses, removes odds,\nand splits array by parity" << endl;
	cout << "Enter numbers (enter after each one): ";
	array_size = 9;
	for (int index = 0; index <= array_size; index++) {
		cin >> user_array[index];
	}

	for (int index = 0; index <= array_size; index++) {
		reverse_array[index] = user_array[index];
		split_array[index] = user_array[index];
	}
	
	cout << "Reverse: ";
	reverseArray(reverse_array, array_size);
	for (int index = 0; index <= array_size; index++) {
		cout << reverse_array[index]<< " ";
	}
	
	cout << "\nOdds Removed: ";
	array_size2 = 9;
	removeOdd(user_array, array_size2);
	for (int index = 0; index <= array_size2; index++) {
		cout << user_array[index] << " ";
	}
	
	cout << "\nSplit: ";
	splitParity(split_array, array_size);
	for (int index = 0; index <= array_size; index++) {
		cout << split_array[index] << " ";
	}

	return 0;
}
void reverseArray(int arr[], int arrSize) {
	int f_temp, r_temp;

	for (int f_index = 0, r_index = arrSize; f_index <= (arrSize / 2); f_index++, r_index--) {
		f_temp = arr[f_index];
		r_temp = arr[r_index];
		//cout << "temps f: " << f_temp << " " << r_temp << endl;
		arr[f_index] = r_temp;
		arr[r_index] = f_temp;
	}
}
void removeOdd(int arr[], int& arrSize) {
	int new_array_size = 0;

	for (int index = 0, even_array_index = 0; index <= arrSize; index++) {
		if ((arr[index] % 2) == 0) {
			arr[even_array_index] = arr[index];
			new_array_size++;
			even_array_index++;
		}
	}
	arrSize = (new_array_size - 1);
}
void splitParity(int arr[], int arrSize) {
	int sort, odds_position, index;

	index = 0;
	odds_position = 0;
	while (index <= arrSize) {
		if ((arr[index] % 2) == 0) {
			sort = arr[odds_position];
			arr[odds_position] = arr[index];
			odds_position++;
			arr[index] = sort;
		}
		index++;
	}
}
void output_int_array(const int arr[]) {

}