#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "check_value.h"
#include "tableActions.h"



int main(int argc, char **argv)
{

	std::cout << "\n\n=============================== Guess the number ===============================\n"
			  << std::endl;

	int maxValue = 0;

	bool incorrectInput = false;

	// Let's print this argument
	if (argc <= 1)
	{
		maxValue = 100;
	}
	// To check - does use print some other argument we should check if the argc >= 2

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
	std::cout << "\n\nHi! Enter your name, please: ";
	std::string userName;
	std::cin >> userName;

	std::cout << "Ok, " << userName << ", let's play!" << std::endl;
	std::cout << "Computer guessed the number in the range from 0 to " << maxValue << ".\n"
			  << "Try to guess it!" << std::endl;
	std::srand((unsigned)std::time(nullptr));

	int attempts = check_value((std::rand() % maxValue));
	std::cout << "You need " << attempts << (attempts > 1 ? " attempts" : " attempt") << " to guess the number.\n\n"
			  << "Now let's see the best results of this game!\n" << std::endl;
	
	putBestScore(userName, attempts);

	printTable();

	exit(0);

	/*// Ask about name
	std::cout << "\n\nHi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

	// Get the last high score
	std::cout << "Enter your high score:" << std::endl;
	int attempts_count = 0;
	getValue(attempts_count, 1, INT_MAX);


	// Write new high score to the records table
	{
		// We should open the output file in the append mode - we don't want
		// to erase previous results.
		std::ofstream out_file{ high_scores_filename, std::ios_base::app };
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		// Append new results to the table:
		out_file << user_name << ' ';
		out_file << attempts_count;
		out_file << std::endl;
	} // end of score here just to mark end of the logic block of code

	// Read the high score file and print all results
	{

	}

	return 0;*/
}