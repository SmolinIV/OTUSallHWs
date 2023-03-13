#include <iostream>
#include <fstream>

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
		// Read the username first
		in_file >> userName;
		// Read the high score next
		in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();

		if (in_file.fail())
		{
			break;
		}

		// Print the information to the screen
		std::cout << userName << "\t\t" << high_score << std::endl;
	}
	std::cout << "goodjob" << std::endl;
	exit(0);
}

// Внесение данных в таблицу
void putBestScore(std::string userName, int userScore)
{
    const std::string high_scores_filename = "high_scores.txt";
    std::string name, score;

    std::fstream ioFile{high_scores_filename, std::fstream::in | std::fstream::out | std::fstream::app};
    if (!ioFile.is_open())
    {
        std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
        exit(-1);
    }

    bool newPlayer = true;

    while (!ioFile.eof())
    {
        ioFile >> name;
        std::cout << name;
        if (name == userName)
        {
            ioFile << userScore;
            newPlayer = false;
            break;
        }
    }

        // Append new results to the table:
        ioFile << userName << ' ';
        ioFile << userScore;
        ioFile << std::endl;
        
}