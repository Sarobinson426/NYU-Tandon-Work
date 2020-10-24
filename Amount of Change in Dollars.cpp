// Author: Shaun Robinson
// Assignment: HW 2 Question 1
// Class: NYU Tandon Bridge Spring 2020
// Program: Quarters Dimes Nickels and Pennies
// Description: a program that asks the	user	to	enter	a	number	of	quarters,	dimes,	nickels and	
// pennies and then	outputs	the	monetary	value	of	the	coins	in	the	format	of	dollarsand
// remaining cents.

#include <iostream>
using namespace std;

const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;

void collect_change(int& input_quarters, int& input_dimes, int& input_nickels, int& input_pennies);
int change_amount(const int& quarter, const int& dime, const int& nickels, const int& pennies);

int main()
{
    int num_quarter, num_dime, num_nickel, num_penny;

    collect_change(num_quarter, num_dime, num_nickel, num_penny);
    int total = change_amount(num_quarter, num_dime, num_nickel, num_penny);

    cout << "Total pennies: " << total << endl;

    return 0;
}

void collect_change(int& input_quarters, int& input_dimes, int& input_nickels, int& input_pennies) {
    cout << "This program totals the amount of change you have in your pocket!" << endl;
    cout << "\nPlease enter number of coins: " << endl;

    cout << "# of quarters: ";
    cin >> input_quarters;

    cout << "# of dimes: ";
    cin >> input_dimes;

    cout << "# of nickels: ";
    cin >> input_nickels;

    cout << "# of pennies: ";
    cin >> input_pennies;
}

int change_amount(const int& quarter, const int& dime, const int& nickels, const int& pennies) {
    int sum_change_dollars, sum_change_change;

    sum_change_dollars = (quarter * QUARTER) + (dime * DIME) + (nickels * NICKEL) + (pennies * PENNY);
    sum_change_change = sum_change_dollars % 100;

    cout << "\n";
    cout << "You have " << sum_change_dollars / 100 << " dollars" << " and " << sum_change_change << " cents!" << "\n";

    return sum_change_dollars;
}