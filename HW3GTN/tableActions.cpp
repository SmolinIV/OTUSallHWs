#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <conio.h>

// Вывод таблицы на экран
void printTable()
{
	const std::string highScoresFilename = "high_scores.txt";
	std::ifstream inFile{highScoresFilename};
	if (!inFile.is_open())
	{
		std::cout << "Failed to open file for read: " << highScoresFilename << "!" << std::endl;
		exit(-1);
	}

	std::cout << "High scores table:" << std::endl;
	std::string userName;
	int high_score = 0;
	while (true)
	{
		// Read the username first
		inFile >> userName;
		// Read the high score next
		inFile >> high_score;
		// Ignore the end of line symbol
		inFile.ignore();

		if (inFile.fail())
		{
			break;
		}

		// Print the information to the screen
		std::cout << userName << "\t\t" << high_score << std::endl;
	}
	inFile.close();

	exit(0);
	
}

// Внесение новых данных в таблицу с учётом
void putBestScore(std::string userName, int userScore)
{
    const std::string highScoresFilename = "high_scores.txt";
	std::string name,
				score;
	int namePositionInTheTable,
		nameInTheTableLength;
	bool isInTheTable = false;


	std::fstream fFile;
	fFile.open(highScoresFilename, std::ios_base::in);

	if (!fFile.is_open())
	{
		std::cout << "Failed to open file for read: " << highScoresFilename << "!" << std::endl;
		exit(-1);
	}

	while (true)
	{
		fFile >> name;
		if (name == userName)
		{
			namePositionInTheTable = (int)fFile.tellg();
			nameInTheTableLength = (int)name.length();
			isInTheTable = true;
		}
		fFile >> score;
		if (isInTheTable)
		{
			if (userScore > std::stoi(score))
			{
				fFile.close();
				return;
			}
		}
		fFile.ignore();
		if (fFile.fail() || isInTheTable)
		{
			break;
		}
	}

	fFile.close();

	if (isInTheTable)
	{
		fFile.open(highScoresFilename, std::ios_base::in | std::ios_base::out | std::ios_base::ate);
		if (!fFile.is_open())
	{
		std::cout << "Failed to open file for write: " << highScoresFilename << "!" << std::endl;
		exit(-1);
	}
		fFile.seekp(namePositionInTheTable - nameInTheTableLength, std::ios_base::beg);
		fFile << std::setw(50) << userName << " " << userScore;
	}
	else
	{
		fFile.open(highScoresFilename, std::ios_base::in | std::ios_base::out | std::ios_base::app);
		if (!fFile.is_open())
	{
		std::cout << "Failed to open file for write: " << highScoresFilename << "!" << std::endl;
		exit(-1);
	}
		fFile << std::setw(50) << userName << " " << userScore << std::endl;
	}

	fFile.close();
}