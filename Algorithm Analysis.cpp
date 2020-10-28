//Author: Shaun Robinson
//Program: Algo Analysis
//Description: Explainations of simple algorithm analysis 
 
#include<iostream>
using namespace std;

//Asymptotic Analysis ?(1), ?(log n), ?(n log n), ?(n), ?(n^2), ?(2^n), ?(n!)
//Upper: Big-O
//Average: Theta
//Lower: Big-Omega

int simple_theta_analysis_n() {
	// Algorithm Analysis is the analysis of how many operations are taking place
	// Each of the i, n, sum are at a 'cost' of 1 operation and these happend only 
	// once each time the function is run
	int i, n, sum;  // ?(1) / each

	sum = 0;        // ?(1)
	n = 20;         // ?(1)
	i = 1;          // ?(1)
	// a loop like a while loop will 'cost' the amount of operations inside of it 
	// for the number of time it iterates e.g. 4 operations n times or big-O(4 * n)
	// always be aware of if/else statements within the loop which may modify this
	cout << "Number of calcs:\n" << endl;
	while (i < n) { // ?(n) 
		sum += i;    // ?(2) one for addition and another for assignments
		//******
		i += 1;      // ?(2) one for additoin and another for assignments
		//******
		
		cout << i << endl;
	}

	return sum;     //  ?(1)
	// overall   ?(n)
}

int simple_theta_analysis_n_slightly_modified() {
	// Algorithm Analysis is the analysis of how many operations are taking place
	// Each of the i, n, sum are at a 'cost' of 1 operation and these happend only 
	// once each time the function is run
	int i, n, sum;  // ?(1) / each

	sum = 0;        // ?(1)
	n = 20;         // ?(1)
	i = 1;          // ?(1)
	// a loop like a while loop will 'cost' the amount of operations inside of it 
	// for the number of time it iterates e.g. 4 operations n times or big-O(4 * n)
	// always be aware of if/else statements within the loop which may modify this
	cout << "Number of calcs:\n" << endl;
	while (i < n) { // ?(n / 2) 
		// The number of operations in this loop is half because 
		// the "i" is incremented up by 2 each time so just like 
		// the above function's loop it adds from i to n but 
		// increments up i += 2 each time cutting the number of 
		// operations in half

		//*** still considered to be  ?(n) even though half the operations 

		sum += i;    // ?(2) one for addition and another for assignments
		//******
		i += 2;      // ?(2) one for additoin and another for assignments
		//******
		cout << i << endl;
	}

	return sum;     //  ?(1)

	// overall  ?(n/2) which is just  ?(n)
}

int simple_theta_analysis_n_with_math() {
	// Algorithm Analysis is the analysis of how many operations are taking place
	// Each of the i, n, sum are at a 'cost' of 1 operation and these happend only 
	// once each time the function is run
	int i, n, sum;  // ?(1) / each

	sum = 0;        // ?(1)
	n = 20;         // ?(1)
	i = 1;          // ?(1)
	// a loop like a while loop will 'cost' the amount of operations inside of it 
	// for the number of time it iterates e.g. 4 operations n times or big-O(4 * n)
	// always be aware of if/else statements within the loop which may modify this
	cout << "Number of calcs:\n" << endl;
	while (i < n) { // ?(log n) 
		// iterations   | value of 'i' | calculation
		// -----------------------------------------
		//     1        |      1       |   2^0
		//     2        |      2       |   2^1
		//     3        |      4       |   2^2
		//     4        |      8       |   2^3
		//    ...       |     ...      |
		//     k        |      n       |  2^(k - 1)

		// set 2^(k - 1) = n and solve for k
		// log2 (2^(k-1)) = log2 n 
		// (k - 1) = log2 n
		// k = log2 n + 1

		sum += i;    // ?(2) one for addition and another for assignments
		//******
		i *= 2;      // ?(2) one for additoin and another for assignments
		//******
		cout << i << endl;
	}

	return sum;     //  ?(1)

	// overall  ?(log n) because it is the highest ...  ?(1) < ?(log n)
}

int main() {
	int theta, theta_modified, theta_log;
	
	theta = simple_theta_analysis_n();
	cout << "Theta += 1: " << theta << endl << endl;

	theta_modified = simple_theta_analysis_n_slightly_modified();
	cout << "Theta modified += 2: " << theta_modified << endl << endl;

	theta_log = simple_theta_analysis_n_with_math();
	cout << "Theta modified *= 2: " << theta_modified << endl << endl;

	return 0;
}