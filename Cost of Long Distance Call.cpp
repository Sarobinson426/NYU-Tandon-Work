// Author: Shaun Robinson
// Class: NYU Tandon Bridge 2020
// Assignment: HW 3 Q6
// Program: Long Distance Call
// Description: Write	a	program	that	computes	the	cost	of	a	long-distance	call.	The	cost	of	 the	call	is	
// determined	according	to	the	following	rate	schedule : Any	call	started	between	8 : 00	A.M. and 6 : 00	P.M., Monday	through	Friday, is	billed	at	a
// rate	of	$0.40	per	minute. Any	call	starting	before	8 : 00	A.M. or after	6 : 00	P.M., Monday	through	Friday, is	charged
// at	a	rate	of	$0.25	per	minute. Any	call	started	on	a	Saturday or Sunday	is	charged	at	a	rate	of	$0.15	per	minute.

#include<iostream>
#include <string>
using namespace std;

void input_day_of_week(string& enter_day, double& enter_call_length, double& enter_call_start);
void call_analysis_ouput(const string& day_of_week, const double& call_length, const double& call_start);

int main()
{
	string day_of_week;
	double call_start, call_length;

	//input
	input_day_of_week(day_of_week, call_length, call_start);

	//output
	call_analysis_ouput(day_of_week, call_length, call_start);

	//alternativley I could have set variable values to the calculations and printed those in an output section

	return 0;
}

void input_day_of_week(string& enter_day, double& enter_call_length, double& enter_call_start) {

	cout << "Please enter day of the week in format Mo, Tu, We, Th, Fr, Sa, Su: " << endl;
	cin >> enter_day;
	
	while (1) {
		if (enter_day == "mo" || enter_day == "Mo" || enter_day == "tu" || enter_day == "Tu" || enter_day == "we" || enter_day == "We" ||
			enter_day == "th" || enter_day == "Th" || enter_day == "Fr" || enter_day == "fr" || enter_day == "sa" || enter_day == "Sa" ||
			enter_day == "su" || enter_day == "Su") {
			break;
		}
		else {
			cout << "You entered " << enter_day << endl;
			cout << "Please enter a day in the format Mo, Tu, We, Th, Fr, Sa, Su: " << endl;
			cin >> enter_day;
		}
	}

	cout << "What time did the call start (24-hr format e.g. 8AM = 800 and 1PM = 1300): ";
	cin >> enter_call_start;
	while (1) {
		if (cin.fail() || (enter_call_start < 0) || (enter_call_start > 2359)) {
			cin.clear();
			cin.ignore(999, '\n');
			cout << "You entered the wrong input please enter either Mo, Tu, We, Th, Fr, Sa, Su: " << endl;
			cin >> enter_call_start;
		}
		if (!cin.fail()) {
			break;
		}
	}

	cout << "Length of the call (minutes): ";
	cin >> enter_call_length;
	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(999, '\n');
			cout << "You entered the wrong input please enter a proper length of time (1 to 2359):" << endl;
			cin >> enter_call_length;
		}
		if (!cin.fail()) {
			break;
		}
	}
}

void call_analysis_ouput(const string& day_of_week, const double& call_length, const double& call_start) {
	string full_day_of_week;

	if (day_of_week == "Mo" || day_of_week == "mo" || day_of_week == "MO") {
		full_day_of_week = "Monday";
	}
	else if (day_of_week == "Tu" || day_of_week == "tu" || day_of_week == "TU") {
		full_day_of_week = "Tuesday";
	}
	else if (day_of_week == "We" || day_of_week == "we" || day_of_week == "WE") {
		full_day_of_week = "Wednesday";
	}
	else if (day_of_week == "Th" || day_of_week == "th" || day_of_week == "TH") {
		full_day_of_week = "Thursday";
	}
	else if (day_of_week == "FR" || day_of_week == "fr" || day_of_week == "FR") {
		full_day_of_week = "Friday";
	}
	else if (day_of_week == "Sa" || day_of_week == "sa" || day_of_week == "SA") {
		full_day_of_week = "Saturday";
	}
	else if (day_of_week == "Su" || day_of_week == "su" || day_of_week == "Su") {
		full_day_of_week = "Sunday";
	}
	//math and calculations 
	if ((day_of_week == "Mo") || (day_of_week == "Tu") || (day_of_week == "We") || (day_of_week == "Th") || (day_of_week == "Fr")
		|| (day_of_week == "mo") || (day_of_week == "tu") || (day_of_week == "we") || (day_of_week == "th") || (day_of_week == "fr")) {
		if ((call_start >= 800) && (call_start <= 1800)) {
			cout << "The call was made on " << full_day_of_week << ", lasted " << call_length << " minutes and costed $" << (0.40 * call_length) << endl;
		}
		else if ((call_start <= 759) || (call_start >= 1801)) {
			cout << "The call was made on " << full_day_of_week << ", lasted " << call_length << " minutes and costed $" << (0.25 * call_length) << endl;
		}
	}
	else if ((day_of_week == "Sa") || (day_of_week == "Su") || (day_of_week == "su") || (day_of_week == "sa")) {
		cout << "The call was made on " << full_day_of_week << ", lasted " << call_length << " minutes and costed $" << (0.15 * call_length) << endl;
	}
}
