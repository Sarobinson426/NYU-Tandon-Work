// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW 7 Q1
// Program: Calendar
// Description: DIY Calendar. Enter the year and day and the years 
// calcendar will be printed for you. 

#include <iostream>
using namespace std;

void input(int& day_year_start, int& year);
int print_month_calendar(int num_days, int starting_day);
void print_year_calender(int year, int starting_day);

int main()
{
	int year, day_year_start;

	input(day_year_start, year);
	print_year_calender(year, day_year_start);

	return 0;
}
void input(int& day_year_start, int& year) {

	cout << "Enter the year: ";
	cin >> year;
	while (cin.fail()) {
		cout << "You entered an illegal character. Please enter an integer year: ";
		cin.clear();
		cin.ignore(999, '\n');
		cin >> year;
	}
	cout << "What day did this year start (e.g. 1 for first, 2 for second...): ";
	cin >> day_year_start;
	while (cin.fail()) {
		cout << "You entered an illegal character. Please enter an integer year: ";
		cin.clear();
		cin.ignore(999, '\n');
		cin >> year;
	}
	while (year < 1 || year > 7) {
		cout << "You entered " << year << " Please enter day of week 1 - 7: ";
		cin >> year;
	}
}
int print_month_calendar(int num_days, int starting_day) {
	int index, num_space, start, day, return_count;

	for (day = 1; day <= 7; day++) {
		switch (day) {
		case 1:
			cout << "Mon" << "\t"; break;
		case 2:
			cout << "Tue" << "\t"; break;
		case 3:
			cout << "Wed" << "\t"; break;
		case 4:
			cout << "Thu" << "\t"; break;
		case 5:
			cout << "Fri" << "\t"; break;
		case 6:
			cout << "Sat" << "\t"; break;
		case 7:
			cout << "Sun" << "\t"; break;
		}
	}
	cout << endl;

	return_count = 0;
	for (num_space = starting_day - 1; num_space > 0; num_space--) {
		cout << "\t";
		return_count++;
	}

	for (index = 1, start = starting_day; index <= num_days; index++, start++) {
		if (start % 7 == 0) {
			cout << index << "\t" << endl;
			return_count++;
		}
		else {
			cout << index << "\t";
			return_count++;
		}
	}

	return_count = return_count % 7;
	cout << endl;
	//cout <<"\n" << return_count << "\n\n";
	return return_count + 1;
}
void print_year_calender(int year, int starting_day) {
	bool is_leap_year1, is_leap_year2, is_leap_year3;
	int leap_year_sum, start, days;
	start = starting_day;

	is_leap_year1 = false;
	if (year % 4 == 0) {
		is_leap_year1 = true;
	}

	is_leap_year2 = false;
	if (year % 100 > 0) {
		is_leap_year2 = true;
	}

	is_leap_year3 = false;
	if (year % 400 == 0) {
		is_leap_year3 = true;
	}
	//cout << "1: " << is_leap_year1 << "\n2: " << is_leap_year2 << "\n3: " << is_leap_year3 << endl;
	leap_year_sum = is_leap_year1 + is_leap_year2 + is_leap_year3;

	//cout << leap_year_sum;
	if (leap_year_sum >= 2) {
		cout << "Leap Year!" << endl;
		for (int months = 1; months <= 12; months++) {
			switch (months) {
			case 1:
				days = 31;
				cout << "January " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 2:
				days = 29;
				cout << "February " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 3:
				days = 31;
				cout << "March " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 4:
				days = 30;
				cout << "April " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 5:
				days = 31;
				cout << "May " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 6:
				days = 30;
				cout << "June " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 7:
				days = 31;
				cout << "July " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 8:
				days = 31;
				cout << "August " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 9:
				days = 30;
				cout << "September " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 10:
				days = 31;
				cout << "October " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 11:
				days = 30;
				cout << "November " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 12:
				days = 31;
				cout << "December " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			}
		}
	}
	if (leap_year_sum <= 1) {
		cout << "Regular Year!" << endl;
		for (int month = 1; month <= 12; month++) {
			switch (month) {
			case 1:
				days = 31;
				cout << "January " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 2:
				days = 28;
				cout << "February" << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 3:
				days = 31;
				cout << "March " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 4:
				days = 30;
				cout << "April " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 5:
				days = 31;
				cout << "May " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 6:
				days = 30;
				cout << "June " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 7:
				days = 31;
				cout << "July " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 8:
				days = 31;
				cout << "August " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 9:
				days = 30;
				cout << "September " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 10:
				days = 31;
				cout << "October " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 11:
				days = 30;
				cout << "November " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			case 12:
				days = 31;
				cout << "December " << year << endl;
				start = print_month_calendar(days, start);
				cout << endl;
				break;
			}
		}
	}
}
