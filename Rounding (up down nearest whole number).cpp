// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW3 Q4
// Program: Real Number Round Ceiling Round Floor
// Description: Write	a	program	that	asks	the	user	to	enter	a	Real	number,	then	it	asks	the	user	to	enter	the
// method	by	which	they	want	to	round	that	number(floor, ceiling or to	the	nearest	integer).
// The	program	will	then	print	the	rounded	result

#include <iostream>
#include <cmath>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

void input(double& number, int& rounding) {
	//input
	cout << "Please enter a real number: " << endl;
	cin >> number;

	cout << "Choose your rounding method (e.g 1, 2, 3): " << endl;
	cout << "1. Floor Round\n"
		<< "2. Ceiling Round\n"
		<< "3. Nearest Whole Number" << endl;
	cin >> rounding;
	while (rounding > 3 || rounding < 1) {
		cout << "Number must be 1, 2, or 3. Please choose a number: " << endl;
		cin >> rounding;
	}
}

void round_number_output(const double& number, const int& round_number);

int main()
{
	double numR;
	int rounding;

	input(numR, rounding);
	round_number_output(numR, rounding);
	
	return 0;
}

void round_number_output(const double& number, const int& round_number) {
	switch (round_number)
	{
	case FLOOR_ROUND:
	{
		cout << "\n" << (int)(number);
		//cout << "\n" << floor(numR);
	}
	break;
	case CEILING_ROUND:
	{
		cout << "\n" << (int)(number + 1);
		//cout << "\n" << ceil(numR);
	}
	break;
	case ROUND:
	{
		cout << "\n" << round(number);
	}
	break;
	default:
		cout << "Invalid input!" << endl;
		break;
	}
}