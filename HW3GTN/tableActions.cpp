#include <iostream>
#include <fstream>
#include <vector>

// Вывод таблицы на экран
void printTable()
{
	const std::string high_scores_filename = "high_scores.txt";
	std::ifstream in_file{high_scores_filename};
	if (!in_file.is_open())
	{
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		exit(-1);
	}

	std::cout << "High scores table:" << std::endl;
	std::string userName;
	int high_score = 0;
	while (true)
	{
		std::cout << in_file.tellg()<< '\t';
		// Read the username first
		in_file >> userName;
		std::cout << in_file.tellg()<< '\t';
		// Read the high score next
		in_file >> high_score;
		std::cout << in_file.tellg()<< '\t';
		// Ignore the end of line symbol
		in_file.ignore();

		if (in_file.fail())
		{
			break;
		}

		// Print the information to the screen
		std::cout << userName << "\t\t" << high_score << "\t\t" << in_file.tellg() << std::endl;
	}
	in_file.close();
	std::cout << "goodjob" << std::endl;
	exit(0);
	
}

// Внесение данных в таблицу
void putBestScore(std::string userName, int userScore)
{
	const int reservedCells = 10;
	std::vector <std::string> namesFromTaable;
	
	namesFromTaable.reserve(reservedCells);
    const std::string high_scores_filename = "high_scores.txt";
    std::string name, score;

    std::fstream ioFile{high_scores_filename, std::fstream::in | std::fstream::out | std::fstream::app};
    if (!ioFile.is_open())
    {
        std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
        exit(-1);
    }
        // Append new results to the table:
        ioFile << userName << ' ';
        ioFile << userScore;
        ioFile << std::endl;
        
}