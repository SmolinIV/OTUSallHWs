#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

// Print table with high scores from file
bool printTable()
{
	const std::string highScoresFilename = "high_scores.txt";
	std::ifstream inFile{highScoresFilename};
	if (!inFile.is_open())
	{
		std::cout << "Failed to open file for read: " << highScoresFilename << "!" << std::endl;
		return false;
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

	return true;
	
}

// Entering new date into the table. Check if the player is in the table. If there is, we record the result of the game if it is better 
// than the current one in the table. If the player is new - write to the end of the file.
bool putBestScore(const std::string& userName, int userScore)
{
    const std::string highScoresFilename = "high_scores.txt";
	std::string name,				// name read from current table
				score;				// score read from current table
	int namePositionInTheTable,		// the position of the read name in the table. Need to replace score when player is in the table
		nameInTheTableLength;		// Length of the read name in the table. need to replace cursor before read name.
	bool isInTheTable = false,
		 fileFound = false;		// We can also control file opening with the flag 'isInTheTable'. This one is created only for code readability.

	std::fstream fFile;
	fFile.open(highScoresFilename, std::ios_base::in);

	if (fFile.is_open())
	{
		fileFound = true;
		while (true)
		{
			fFile >> name;
			if (name == userName)
			{
				namePositionInTheTable = (int)fFile.tellg();
				nameInTheTableLength = (int)name.size();
				isInTheTable = true;
			}
			fFile >> score;
			if (isInTheTable)
			{
				// If player is in the table but score of current game is worse - close this function without any file changes
				if (userScore > std::stoi(score))
				{
					fFile.close();
					return true;
				}
			}
			fFile.ignore();
			if (fFile.fail() || isInTheTable)
			{
				break;
			}
		}

		fFile.close();
	}

	if (isInTheTable && fileFound)
	{
		fFile.open(highScoresFilename, std::ios_base::in | std::ios_base::out | std::ios_base::ate);
		if (!fFile.is_open())
		{
			std::cout << "Failed to open file for write: " << highScoresFilename << "!" << std::endl;
			return false;
		}
		fFile.seekp(namePositionInTheTable - nameInTheTableLength, std::ios_base::beg);
		fFile << userName << " "  << std::setw(4) << std::left << userScore;
	}
	else
	{
		fFile.open(highScoresFilename, std::ios_base::in | std::ios_base::out | std::ios_base::app);
		if (!fFile.is_open())
	{
		std::cout << "Failed to open file for write: " << highScoresFilename << "!" << std::endl;
		return false;
	}
	// The new score overwrite the current one taking into account the digits of the number
		fFile << userName << " " << std::setw(4) << std::left<< userScore << std::endl;
	}

	fFile.close();

	return true;
}