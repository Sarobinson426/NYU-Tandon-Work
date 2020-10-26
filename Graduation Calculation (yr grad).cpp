// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW3 Q2
// Program: 
// Description: Write	a	program	that asks the	user for	their	name, 
// their graduation	year, and input	the	current	year.
// Assume the student is in	a four - year	undergraduate	program. 
// Displays the current	status the of student, not in college yet, freshman, sophomore, junior, senior, or graduated.

#include <iostream>
#include <string>
using namespace std;

void input_name_year(int& grad_yr, int& current_yr, int& yr_span, string& name);
string grad_status(const int& yr_span);

int main()
{
	string name, graduation;
	int grad_yr, current_yr, yr_span;

	//Input 
	input_name_year(grad_yr, current_yr, yr_span, name);

	//Math and calculations 
	//Possible	status	include:	not	in	college	yet,	freshman,	sophomore,	junior,	senior,	graduated.
	graduation = grad_status(yr_span);
	
	//Output
	cout << name << ", you are "<< graduation<< "!"<<endl;

	return 0;
}

void input_name_year(int& grad_yr, int& current_yr, int& yr_span, string& name) {
	cout << "Please enter your name: ";
	getline(cin, name);
	cout << "Please enter your graduation year: ";
	cin >> grad_yr;
	cout << "Please enter you current year: ";
	cin >> current_yr;

	yr_span = (grad_yr - current_yr);
}

string grad_status(const int& yr_span) {
	string graduation;

	if (yr_span == 3) {
		graduation = "a freshman";
	}
	else if (yr_span == 2) {
		graduation = "a sophomore";
	}
	else if (yr_span == 1) {
		graduation = "a junior";
	}
	else if (yr_span == 0) {
		graduation = "a senior";
	}
	else if (yr_span < 0) {
		graduation = "graduated";
	}
	else if (yr_span > 4) {
		graduation = "not in school yet";
	}

	return graduation;
}