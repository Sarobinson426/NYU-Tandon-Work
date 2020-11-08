// Author: Shaun Robinson
// "How do you get to Carniege Hall???
// Practice, Practice, Practice

#include<iostream>
#include<ctime>
using namespace std;

void merge_sort(int* arr, int* temp, int begin, int end);
void merge(int* arr, int* temp, int begin, int end);

int main() {
	int *arr, *temp, size;
	
	cout << "This program will sort an array created randomly" << endl;
	cout << "of a size of your choosing..." << endl;
	cout << "Enter the size of array you want: ";
	cin >> size;

	arr = new int[size];
	temp = new int[size];
	srand(time(0));
	cout << "Original array: ";
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << " ";
	}
	cout << endl;

	merge_sort(arr, temp, 0, size - 1);

	cout << "Sorted array: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}

void merge_sort(int* arr, int* temp, int begin, int end) {
	if (begin >= end) {
		return;
	}
	else {
		int middle = (begin + end) / 2;
		
		merge_sort(arr, temp, begin, middle);
		merge_sort(arr, temp, middle + 1, end);
		merge(arr, temp, begin, end);
	}
}
void merge(int* arr, int* temp, int begin, int end) {
	int leftend = (begin + end) / 2;
	int rightstart = leftend + 1;

	int left = begin;
	int right = rightstart;
	int k = begin;

	while (left <= leftend && right <= end) {
		if (arr[left] < arr[right]) {
			temp[k] = arr[left];
			left++;
		}
		else {
			temp[k] = arr[right];
			right++;
		}
		k++;
	}

	while (left <= leftend) {
		temp[k] = arr[left];
		k++;
		left++;
	}
	while (right <= end) {
		temp[k] = arr[right];
		k++;
		right++;
	}

	for (int i = begin; i < k; i++) {
		arr[i] = temp[i];
	}
}

