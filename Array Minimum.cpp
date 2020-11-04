// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW8 Q1
// Program: Search array for min value
// Description: This function is given arr, an array of integers, and its logical size, arrSize. When called,
// it returns the minimum value in arr.

#include <iostream>
using namespace std;

int* input_into_array(int& arr_size);
int min_in_array(const int arr[], int& arr_size);

int main()
{
	cout << "Enter an array of distinct integers and find the minimum value in that array\nand it's location" << endl;
	int* users_array, minimum, size_of_arr;

	users_array = input_into_array(size_of_arr);

	minimum = min_in_array(users_array, size_of_arr);
	
	cout << "Minimum value is: " << minimum << endl;
	cout << "Minimum vlaue is located at: " << size_of_arr << endl;

	return 0; 
}
int* input_into_array(int& arr_size) {
	int* users_array, minimum, size_of_arr;

	cout << "How large of an array: ";
	cin >> size_of_arr;
	while (cin.fail() || size_of_arr <= 1) {
		cout << "You entered an invalid input. Enter an integer greater than 1: ";
		cin.clear();
		cin.ignore(999, '\n');
		cin >> size_of_arr;
	}
	users_array = new int[size_of_arr];

	cout << "Enter numbers into your array: ";
	for (int index = 0; index < size_of_arr; index++) {
		cin >> users_array[index];
	}

	arr_size = size_of_arr;
	return users_array;
}
int min_in_array(const int arr[], int& arr_size) {
	int min_val = arr[0], min_location;
	
	min_location = 0;
	for (int index = 1; index < arr_size ; index++) {
		if (arr[index] < min_val) {
			min_val = arr[index];
			min_location = index;
		}
	}

	arr_size = min_location;
	return min_val;
}
