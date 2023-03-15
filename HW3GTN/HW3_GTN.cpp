#include <iostream>
#include <fstream>
#include <string>
#include "check_value.h"
#include "tableActions.h"

int main(int argc, char **argv)
{

	std::cout << "\n\n=============================== Guess the number ===============================\n"
			  << std::endl;


	int maxValue = 0;				// upper limit of guessing range. set when receiving parameters
	bool incorrectInput = false;	// Flag of incorrect parameter input. if true, the program will close with errorCode -1;

	// Parameter processing:
	// Default value, when the program start without any parameters
	if (argc <= 1)
	{
		maxValue = 100;
	}
	
	// Processing parameter -table, -level and -max. For the last two, checking the third parameter for 0 excludes their simultaneous writing
	if (argc >= 2)
	{
		std::string arg1Value = argv[1];
		int parameterValue = 0;

		if (arg1Value == "-table")
		{
			if (argc != 2)
			{
				incorrectInput = true;
			}
			else
			{
				printTable();
			}
		}
		else if (arg1Value == "-max")
		{
			if (argc != 3)
			{
				incorrectInput = true;
			}
			else
			{
				parameterValue = std::atoi(argv[2]);
				if (parameterValue <= 0)
				{
					incorrectInput = true;
				}
				else
				{
					maxValue = parameterValue;
				}
			}
		}
		else if (arg1Value == "-level")
		{
			if (argc != 3)
			{
				incorrectInput = true;
			}
			else
			{
				parameterValue = std::atoi(argv[2]);
				switch (parameterValue)
				{
				case 1:
					maxValue = 10;
					break;
				case 2:
					maxValue = 50;
					break;
				case 3:
					maxValue = 100;
					break;
				default:
					incorrectInput = true;
				}
			}
		}
		else
		{
			incorrectInput = true;
		}
	}

	if (incorrectInput)
	{
		std::cout << "Incorrect parameter input." << std::endl;
		return -1;
	}

	// Ask about name
	std::string userName;

	std::cout << "\n\nHi! Enter your name, please: ";
	std::cin >> userName;

	std::cout << "Ok, " << userName << ", let's play!" << std::endl;
	std::cout << "Computer pick the number in the range from 0 to " << maxValue << ".\n"
			  << "Try to guess it!" << std::endl;
	
	std::srand((unsigned)std::time(nullptr));

	// Declare a variable and run the function of the guessing process, the result of which will be assigned to the variable
	int attempts = check_value((std::rand() % maxValue)); 

	//Print result
	std::cout << "You need " << attempts << (attempts > 1 ? " attempts" : " attempt") << " to guess the number.\n\n"
			  << "Now let's see the best results of this game!\n" << std::endl;
	
	// Put the best score (or new player with his score) to the table "high_scores"
	putBestScore(userName, attempts);

	// Print table
	printTable();

	return 0;
}