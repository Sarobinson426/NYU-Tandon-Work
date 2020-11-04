// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW8 Q1
// Program: Pin and password 
// Description: Program generates a random array to check 
// the correct user pin

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void password();

void password_gen(int arr[], int arr_size);
// populates an array with random numbers
// input: array, array size
// output: none, -modifies array with random numbers
// assumptions: needs array declared in main

bool password_check(int arr[], int arr_size, int user_pin);
// checks array between user pin and random password in array 
// can alternatively check array totals
// input: array, array size, and users pin
// output: true / false
// assumptions: user inputs pin in main

int main() {
	int pin;

	password();
	
	return 0;
}
void password() {
	int num_array[10] = { 0 }, arr_size = 9;
	int correct, pin;

	cout << "Please enter your 5 digit password according to the following mapping: " << endl;
	cout << "PIN:\t";
	for (int index = 0; index <= arr_size; index++) {
		num_array[index] = index;
		cout << num_array[index] << " ";
	}
	password_gen(num_array, arr_size);
	cout << "\nNUM:\t";
	for (int index = 0; index <= arr_size; index++) {
		cout << num_array[index] << " ";
	}
	cout << endl;
	cin >> pin;

	correct = password_check(num_array, arr_size, pin);
	if (correct == true) {
		cout << "Your password is correct sir!!!";
	}
	else {
		cout << "Incorrect.";
	}
}
void password_gen(int arr[], int arr_size) {
	int rand_num;
	srand(time(0));

	for (int index = 0; index <= arr_size; index++) {
		rand_num = (rand() % 10);
		arr[index] = rand_num;
	}
}
bool password_check(int arr[], int arr_size, int user_pin) {
	int pin_total, password_total, index, pin_correctness;
	bool correct_pin;
	
	index = 5;
	pin_correctness = 0;
	while (user_pin != 0) {
		//cout << "array: " << arr[index] << "\tuser pin: " << user_pin % 10 << endl;
		if (user_pin % 10 == arr[index]) {
			pin_correctness++;
		}
		user_pin /= 10;
		index--;
	}

	correct_pin = false;
	if (pin_correctness == 5) {
		correct_pin = true;
	}

	return correct_pin;
}