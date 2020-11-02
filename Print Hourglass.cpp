// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW4 Q5
// Program: Hour Glass
// Description: draws the shape of an hour glass depending upon user input
// "How do you get to Carniege Hall???
// Practice, Practice, Practice

#include <iostream>
using namespace std;

void input(int& size);
void top_of_hour_glass(const int& size);
void bottom_of_hour_glass(const int& size);

int main()
{
	int size, line_count, star_count, space_count, num_stars, num_spaces;

	input(size);
	top_of_hour_glass(size);
	bottom_of_hour_glass(size);
	
	return 0;
}

void input(int& size) {
	cout << "Enter the size of the hourglass: ";
	cin >> size;
}

void top_of_hour_glass(const int& size) {
	int line_count, star_count, space_count, num_stars, num_spaces;

	for (line_count = 1, num_spaces = 0, num_stars = ((2 * size) - 1);
		line_count <= size;
		line_count++, num_spaces++, num_stars -= 2) {
		//print a sequence of num_spaces spaces 
		for (space_count = 0; space_count <= num_spaces; space_count++) {
			cout << " ";
		}
		//print a sequence of num_stars stars 
		for (star_count = 1; star_count <= num_stars; star_count++) {
			cout << "*";
		}
		//break the line
		cout << endl;
	}
}

void bottom_of_hour_glass(const int& size) {
	int line_count, star_count, space_count, num_stars, num_spaces;

	for (line_count = 1, num_spaces = (((2 * size) - 1) / 2), num_stars = 1;
		line_count <= size;
		line_count++, num_spaces--, num_stars += 2) {
		//print a sequence of num_spaces spaces 
		for (space_count = 0; space_count <= num_spaces; space_count++) {
			cout << " ";
		}
		//print a sequence of num_stars stars 
		for (star_count = 1; star_count <= num_stars; star_count++) {
			cout << "*";
		}
		//break the line 
		cout << endl;
	}
}