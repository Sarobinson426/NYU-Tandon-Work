// Author: Shaun Robinson
// Assignment: HW 2 Question 2
// Class: NYU Tandon Bridge Spring 2020
// Program: Dollars and Cents 
// Description: Write	a	program	that	asks the	user	to	enter	an	amount	of	money	in	the	format	of	dollars	and	
// remaining	cents.The	program	should	calculate and print	the	minimum	number	of	coins
// (quarters, dimes, nickelsand pennies)	that	are	equivalent	to	the	given	amount.

#include <iostream>
using namespace std;

const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;

void dollars_and_cents(int& input_dollars, int& input_cents);
void calculate_change(const int& dollars, const int& cents);

int main()
{
	int dollars, cents;
	
	dollars_and_cents(dollars, cents);

	calculate_change(dollars, cents);
	
	return 0;
}

void dollars_and_cents(int& input_dollars, int& input_cents) {
	int dollars, cents, input;
	char period;

	//input
	cout << "This program converts dollars and cents into minimum number of coins!" << endl;
	cout << "Please enter your amount in the format of dollars and cents (e.g. $3.50): $";
	cin >> dollars;
	cin.ignore(1, '.');
	cin >> cents;

	input_dollars = dollars;
	input_cents = cents;
}

void calculate_change(const int& dollars, const int& cents) {
	int dollar_quarters, total_quarters, cents_quarters, dimes, nickels, pennies;

	dollar_quarters = ((dollars * 100) / QUARTER);
	cents_quarters = (cents / QUARTER);
	total_quarters = (dollar_quarters + cents_quarters);

	dimes = ((cents - (cents_quarters * QUARTER)) / DIME);
	nickels = ((cents - ((cents_quarters * QUARTER) + (dimes * 10))) / NICKEL);
	pennies = ((cents - ((cents_quarters * QUARTER) + (dimes * 10) + (nickels * NICKEL))) / PENNY);

	//output 
	cout << "$" << dollars << " and " << cents << " cents are: " << endl;
	cout << total_quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << "and " << pennies << " pennies" << endl;
}