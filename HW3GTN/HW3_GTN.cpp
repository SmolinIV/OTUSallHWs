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
	
	//putBestScore(userName, attempts);

	printTable();

	exit(0);
}