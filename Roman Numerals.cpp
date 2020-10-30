// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW4 Q2 
// Program: Roman Numerals  
// Description: In this question we will use a simplified version of the Roman Numerals System to represent
// positive integers.

#include <iostream>
using namespace std;

const int I = 1;
const int V = 5;
const int X = 10;
const int L = 50;
const int C = 100;
const int D = 500;
const int M = 1000;

void print_roman_numeral(int roman_numeral);

int main()
{
	int roman_numeral, print_numeral;

	cout << "Enter a decimal number to convert to simplified roman numerals: ";
	cin >> roman_numeral;

	print_roman_numeral(roman_numeral);

	return 0;
}

void print_roman_numeral(int roman_numeral) {
	int m_numeral, d_numeral, c_numeral, l_numeral, x_numeral, v_numeral, i_numeral, print_numeral;

	while (roman_numeral > 0) {
		if (roman_numeral >= M) {
			print_numeral = roman_numeral / M;
			for (m_numeral = 0; m_numeral < print_numeral; m_numeral++) {
				cout << 'M';
			}
			roman_numeral = roman_numeral % M;
		}
		else if (roman_numeral >= D) {
			print_numeral = roman_numeral / D;
			for (d_numeral = 0; d_numeral < print_numeral; d_numeral++) {
				cout << 'D';
			}
			roman_numeral = roman_numeral % D;
		}
		else if (roman_numeral >= C) {
			print_numeral = roman_numeral / C;
			for (c_numeral = 0; c_numeral < print_numeral; c_numeral++) {
				cout << 'C';
			}
			roman_numeral = roman_numeral % C;
		}
		else if (roman_numeral >= L) {
			print_numeral = roman_numeral / L;
			for (l_numeral = 0; l_numeral < print_numeral; l_numeral++) {
				cout << 'L';
			}
			roman_numeral = roman_numeral % L;
		}
		else if (roman_numeral >= X) {
			print_numeral = roman_numeral / X;
			for (x_numeral = 0; x_numeral < print_numeral; x_numeral++) {
				cout << 'X';
			}
			roman_numeral = roman_numeral % X;
		}
		else if (roman_numeral >= V) {
			print_numeral = roman_numeral / V;
			for (v_numeral = 0; v_numeral < print_numeral; v_numeral++) {
				cout << 'V';
			}
			roman_numeral = roman_numeral % V;
		}
		else if (roman_numeral >= I) {
			print_numeral = roman_numeral / I;
			for (i_numeral = 0; i_numeral < print_numeral; i_numeral++) {
				cout << 'I';
			}
			roman_numeral = 0;
		}
	}
}