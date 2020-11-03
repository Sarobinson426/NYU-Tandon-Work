// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW5 Q2
// Program: Guess
// Description: Implement	a	number	guessing	game.	The	program	should	randomly	choose	an	integer	
// between	1 and 100	(inclusive), and have	the	user	try	to	guess	that	number.


#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void create_target(int& guess);
void narrow_down_guesses(const int& guess);

int main()
{
	int target;
	
	create_target(target);
	narrow_down_guesses(target);
	

	return 0;
}

void create_target(int& guess) {

	srand(time(0));

	guess = (rand() % 100) + 1;

	cout << "This is a guessing game. Pick a number between 1 and 100."
		"\nI will tell you if this number is too high or too low or if you guessed it."
		"\nI thought of a number between 1 - 100. Try to guess it!" << endl;
}

void narrow_down_guesses(const int& guess) {
	int user_guess, num_guess, guesses_left;
	int new_lower_range, new_upper_range;

	new_upper_range = 100;
	new_lower_range = 0;

	for (num_guess = 1, guesses_left = 5; num_guess <= 5; num_guess++, guesses_left--) {
		cout << "Range: [" << new_lower_range << ", " << new_upper_range << "]. Guesses left: " << guesses_left << endl;

		cout << "Your guess: ";
		cin >> user_guess;

		if (user_guess == guess) {
			cout << "Fantastic you guessed it in " << num_guess << " guesses! My number was " << guess << "!" << endl;
			break;
		}

		if (num_guess == 5) {
			cout << "Too many guesses! The correct number is " << guess << endl;
			break;
		}

		if (user_guess > guess) {
			cout << "Too High! Guess again!\n" << endl;
			if (user_guess <= new_upper_range)
				new_upper_range = user_guess - 1;
		}
		else if (user_guess < guess) {
			cout << "Too low! Guess again!\n" << endl;
			if (user_guess >= new_lower_range)
				new_lower_range = user_guess + 1;
		}

	}
}