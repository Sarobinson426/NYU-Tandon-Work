// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW9 Q4
// Program: Sort Odd to front and Flip Even in array
// Input: integer array
// Output: sorted array with odds at beginning and evens in back sorted
// in reverse of their previous order
// Description: 

#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

int* create_initialize_arr(int& arr_size);

void oddsKeepEvensFlip(int arr[], int arrSize);

int main()
{
	int* arr, arr_size;

	arr = create_initialize_arr(arr_size);
	
	oddsKeepEvensFlip(arr, arr_size);
	
	delete[] arr;

	return 0;
}
int* create_initialize_arr(int& arr_size) {
	cout << "This proram will generate a random array and sort it first by parity" << endl;
	cout << "then sort the evens while leaving the odds in their original order" << endl;
	cout << "This is an 'in place' sort" << endl;
	cout << "Enter an array size: ";
	cin >> arr_size;

	int* arr;
	arr = new int[arr_size];

	// initialize all arr[] to NULL
	for (int index = 0; index < arr_size; index++) {
		arr[index] = NULL;
	}
	for (int index = 0; index < arr_size; index++) {
		arr[index] = rand() % 100 + 1;
	}

	cout << "Initial array: " << endl;
	for (int index = 0; index < arr_size; index++) {
		cout << arr[index] << " ";
	}
	cout << endl;

	return arr;
}
void oddsKeepEvensFlip(int arr[], int arrSize) {
	int index, r_index, oddex, evendex;
	int odd, even;

	for (index = 0, r_index = (arrSize - 1), oddex = 0; index < arrSize; index++, r_index--) {
		if ((arr[index] % 2) == 1) {
			odd = arr[index];
			arr[index] = arr[oddex];
			arr[oddex] = odd;
			oddex++;
		}
	}
	for (evendex = (arrSize - 1), r_index = (arrSize - 1); r_index > 0; r_index--) {
		if ((arr[r_index] % 2) == 0) {
			even = arr[r_index];
			arr[r_index] = arr[evendex];
			arr[evendex] = even;
			evendex--;
		}
	}

	int sort_index = 0;
	int start_sort;
	bool is_first_even = false;
	while (is_first_even == false) {
		if (arr[sort_index] % 2 == 0) {
			start_sort = sort_index;
			is_first_even = true;
		}
		sort_index++;
	}

	for (int i = start_sort; i < arrSize; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= start_sort && arr[j] > key) {
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}

	cout << "Odds first, evens last and evens sorted: ";
	for (int index = 0; index < arrSize; index++) {
		cout << arr[index] << " ";
	}
}