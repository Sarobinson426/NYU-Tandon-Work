// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW3 Q3
// Program: 
// Description: Write	a	program	that	does	the	following:
// • Ask	user	to	input	three	Real numbers	a, band c.They	represent	the	parameters	of	a
// quadratic	equation	
// • Classify	to	one	of	the	following :
// -’Infinite	number	of	solutions’	infinite
//	number	of	solutions)
//	- ’No	solution’(for	example,  has	no	solution)
//	- ’No	real	solution’(for	example,  has	no	real	solutions)
//	- ’One	real	solution’
//	- ’Two	real	solutions’
//	• In	cases	there	are	1 or 2	real	solutions, also	print	the	solutions.

#include <iostream>
#include <cmath>
using namespace std;

double input(double& valA, double& valB, double& valC);
void solutions(const double& valA, const double& valB, const double& valC, const double& valSqr);

int main()
{
	double valA, valB, valC, valSqr;

	//input
	valSqr = input(valA, valB, valC);

	//for testing
	//cout << "Value of discriminant: " <<valSqr << endl;
	solutions(valA, valB, valC, valSqr);
	
	return 0;
}

double input(double& valA, double& valB, double& valC) {
	cout << "Please enter a value for a: ";
	cin >> valA;
	cout << "Please enter a value for b: ";
	cin >> valB;
	cout << "Please enter a value for c: ";
	cin >> valC;

	return ((valB * valB) - (4 * valA * valC));
}

void solutions(const double& valA, const double& valB, const double& valC, const double& valSqr) {
	double result1, result2;
	
	if ((valA == 0) && (valB == 0)) {
		cout << "No solution!" << endl;
	}
	else if ((valA == 0)) {
		cout << "No solution!" << endl;
	}
	else if (valSqr > 0) {
		result1 = (-(valB) + (sqrt(valSqr))) / (2 * valA);
		result2 = (-(valB) - (sqrt(valSqr))) / (2 * valA);
		cout << "Two real solutions x = " << result1 << " and x = " << result2 << endl;
	}
	else if (valSqr == 0) {
		result1 = ((-(valB)) / (2 * valA));
		cout << "One real solutions x = " << result1 << endl;
	}
	else if (valSqr < 0) {
		cout << "No real solution!" << endl;
	}
	else {
		cout << "Infinite solutions!" << endl;
	}
}