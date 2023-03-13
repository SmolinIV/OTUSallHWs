#include <iostream>
#include <fstream>
#include <string>
#include "check_value.h"


// јлгоритм игры. «апрашиваем у игрока число, сравниваем его с загаданным. ≈сли не совпало - подсказываем, больше число игрока или меньше.
// ≈сли совпало - возвращаем количество попыток.
int check_value(const int guessedNumber)
{

	int userNumber;
	int attempts = 0;
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