// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW3 Q5
// Program: BMI
// Description: Body	mass	index	(BMI)	is	a	number	calculated	from	a	person’s	weight	and	height	using	the	
// following	formula : w/h^2. Where weight is	in	kilograms and height is	in	meters.

#include <iostream>
using namespace std;

void input_height_weight(double& weight, double& height);
void bmi_calc_output(const double& weight, const double& height);

int main()
{
	double weight_lbs, weight_kgs, bmi;
	double height_in, height_m;

	//input
	input_height_weight(weight_lbs, height_in);

	//math and calculations 
	bmi_calc_output(weight_lbs, height_in);

	return 0;
}

void input_height_weight(double& weight, double& height) {
	cout << "Please enter your weight in pounds (lbs): ";
	cin >> weight;

	cout << "Please enter your height in inches (in.): ";
	cin >> height;
}

void bmi_calc_output(const double& weight, const double& height) {
	double weight_kgs, height_m, bmi;
	
	weight_kgs = weight * 0.453592;
	height_m = height * 0.0254;

	bmi = ((weight_kgs) / ((height_m * height_m)));
	//for testing
	//cout << "BMI: " << bmi << endl;

	if (bmi < 18.5) {
		cout << "The weight status is: Underweight" << endl;
	}
	else if (bmi < 25) {
		cout << "The weight status is: Normal" << endl;
	}
	else if (bmi < 30) {
		cout << "The weight status is: Overweight" << endl;
	}
	else if (bmi >= 30) {
		cout << "The weight status is: Obese" << endl;
	}
}