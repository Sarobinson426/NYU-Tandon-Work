// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW2 Question 3
// Program: Days Hours Minutes
// Description: Suppose	two employees worked	for	some	time	and	we	want	to	calculate	the	total	time	both	of	
// them	worked. Write	a	program	that	reads number	of	days, hours, minutes	each	of	them
// worked, and prints	the	total	time	both	of	them	worked	together	as	days, hours, minutes.

#include <iostream>
#include <string>
using namespace std;

void input_time_worked(int& total_days, int& total_hours, int& total_minutes, string name);
void time_worked(const int& entered_days, const int& entered_hours, const int& entered_minutes, const string names[]);

int main()
{
    int total_days, total_hours, total_minutes, name_place;
    string name[2], employee_name;

    cout << "This program calculates how many Days Hours and Minutes John and Bill worked!" << endl;

    name_place = 0;
    total_days = 0;
    total_hours = 0;
    total_minutes = 0;
    for (int i = 0; i <= 1; i++) {
        cout << "Enter name of employee: ";
        cin >> employee_name;
        input_time_worked(total_days, total_hours, total_minutes, employee_name);
        name[name_place] = employee_name;
        name_place++;
    }

    time_worked(total_days, total_hours, total_minutes, name);

    return 0;
}

void input_time_worked(int& total_days, int& total_hours, int& total_minutes, string name) {
    int days, hours, minutes;

    cout << "Please enter the number of days " << name << " worked: ";
    cin >> days;
    cout << "Please enter the number of hours " << name << " worked: ";
    cin >> hours;
    cout << "Please enter the number of minutes " << name << " worked: ";
    cin >> minutes;

    total_days += days;
    total_hours += hours;
    total_minutes += minutes;
}

void time_worked(const int& entered_days, const int& entered_hours, const int& entered_minutes, const string names[]) {
    int minutes, converted_minutes, hours, converted_hours, days;

    minutes = (entered_minutes) % 60;
    converted_minutes = (entered_minutes) / 60;

    hours = (entered_hours + converted_minutes) % 24;
    converted_hours = (entered_hours + converted_minutes) / 24;

    days = (entered_days + converted_hours);

    //output
    cout << "\nThe total time both " << names[0] << " and " << names[1] << " have worked together is " << days << " days, ";
    cout << hours << " hours, " << minutes << " minutes! " << endl;
}