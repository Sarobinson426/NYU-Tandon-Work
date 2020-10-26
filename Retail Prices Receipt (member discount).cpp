// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW3 Q1
// Program: Two Items and BOGO
// Description: Write	a	program	that	computes	how	much	a	customer	has	to	pay	after	purchasing	two	
// items. The	price	is	calculated	according	to	the	following	rules :
// • Buy	one	get	one	half	off	promotion : the	lower	price	item	is	half	price.
// • If	the	customer	is	club	card	member, additional	10 % off.
// • Tax	is	added.

#include <iostream>
using namespace std;

void input_prices(double& item1, double& item2, bool& member);
double calculate_prices(double& item1_price, double& item2_price, double& discounted_item, double& the_base_price, double& the_member_price, double& the_total_price, double& tax, const bool& member);
void output(const double& item1, const double& item2, const double& discounted_item, const double& the_base_price, const double& taxes, const double& the_member_price, const bool& member);

int main()
{
	double item1, item2, discounted_item, base_price, bogo_price, total_price, member_price, tax;
	bool member;

	//input 
	member = false;
	input_prices(item1, item2, member);

	//math and calculations: discount price, member price, taxes 
	total_price = calculate_prices(item1, item2, discounted_item, base_price, member_price, total_price, tax, member);
	
	output(item1, item2, discounted_item, base_price, tax, member_price, member);

	return 0;
}

void input_prices(double& item1, double& item2, bool& member) {
	double enter_item1, enter_item2;
	char y_n_club;

	cout << "Enter the price of the first item: $";
	cin >> enter_item1;

	cout << "Enter the price of the second item: $";
	cin >> enter_item2;

	cout << "Does the customer have a club card: ";
	cin >> y_n_club;

	member = false;
	if ((y_n_club == 'Y') || (y_n_club == 'y')) {
		member = true;
	}
	else if ((y_n_club != 'N') || (y_n_club != 'n')) {
		member = false;
	}

	item1 = enter_item1;
	item2 = enter_item2;
}

double calculate_prices(double& item1_price, double& item2_price, double& discounted_item, double& the_base_price, double& the_member_price, double& the_total_price, double& tax, const bool& member) {

	the_base_price = item1_price + item2_price;
	if (item1_price < item2_price) {
		discounted_item = (item1_price * 0.5);
		the_base_price = item1_price + discounted_item;
	}
	else if (item1_price > item2_price) {
		discounted_item = (item2_price * 0.5);
		the_base_price = discounted_item + item2_price;
	}
	else if (item1_price == item2_price) {
		discounted_item = (item2_price * 0.5);
		the_base_price = item1_price + discounted_item;
	}

	if (member) {
		the_total_price = the_base_price;
		the_member_price = the_base_price * 0.90;
	}
	else {
		the_total_price = the_base_price;
		the_member_price = the_base_price;
	}

	cout << "Enter taxrate (e.g. 5.5 for %5.5): %";
	cin >> tax;
	tax /= 100;

	return the_total_price + (the_total_price * tax);
}

void output(const double& item1, const double& item2, const double& discounted_item, const double& the_base_price, const double& taxes, const double& the_member_price, const bool& member) {
	
	if ((item1 + discounted_item) < (item2 + discounted_item)) {
		cout << "Item 1: \t$" << item1 << endl;
		cout << "\t\t-" << (item1 - discounted_item) << endl;
		cout << "Discount price: $" << discounted_item << endl;
		cout << "Item 2: \t$" << item2 << endl;
		cout << "Sub Total: \t$" << the_base_price << endl;
	}
	else {
		cout << "Item 1: \t$" << item1 << endl;
		cout << "Item 2: \t$" << item2 << endl;
		cout << "\t\t-" << (item2 - discounted_item) << endl;
		cout << "Discount price: $" << discounted_item << endl;
		cout << "Sub Total: \t$" << the_base_price << endl;
	}
	if (member == true) {
		cout << "Member price:\t$" << (the_member_price) << endl;
		cout << "Member tax:\t$" << (the_member_price * taxes) << endl;
		cout << "Member total:\t$" << the_member_price + (the_member_price * taxes) << endl;
		cout.precision(4);
		cout << "Savings:\t$" << (the_base_price + (the_base_price * taxes)) - (the_member_price + (the_member_price * taxes)) << endl;
	}
	else {
		cout << "Tax rate: " << (taxes * 100) << "%\t$";
		cout.precision(4);
		cout << (the_base_price * taxes) << endl;
		cout << "Total:\t\t$" << the_base_price + (the_base_price * taxes) << endl;
	}
}