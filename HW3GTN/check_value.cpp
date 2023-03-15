#include <iostream>
#include <fstream>
#include <string>
#include "check_value.h"


// Guessing proccess. We ask the player for a number, compare it with the guessed one. If it doesn't match, we suggest whether the player's number is greater or less.
// If it matches, we report victory and return the number of attempts.
int check_value(const int guessedNumber)
{

	int userNumber;		// Nubmer entered by user
	int attempts = 0;	// user's attemts to guess the number
	while (true)
	{
		std::cout << "Enter your guess: ";
		std::cin >> userNumber;

		if(std::cin.fail())
		{
			std::cout << "Incorrect input." << std::endl;
			exit(-1);
		}

		++attempts;
		if (guessedNumber > userNumber)
		{
			std::cout << "Hidden number is greater than " << userNumber << std::endl;
		}
		else if (guessedNumber < userNumber)
		{
			std::cout << "Hidden number is less than " << userNumber << std::endl;
		}
		else
		{
			std::cout << "You win!" << std::endl;
			break;
		}

	}

	return attempts;
}