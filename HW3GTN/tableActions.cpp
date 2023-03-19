#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

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
	std::string tableData = "";
	while (true)
	{
		std::getline(inFile, tableData);
		std::replace(tableData.begin(), tableData.end(), '|', '\t');
		//inFile.ignore();

		if (inFile.fail())
		{
			break;
		}
		std::cout << tableData << std::endl;
		// Print the information to the screen
	//	std::cout << userName << "\t\t" << high_score << std::endl;
	}
	inFile.close();

	return true;
	
}

// Enter new date into the table. Ñount the number of lines in the file, create an array for them and put them in this array, 
// after which we isolate the name and score data from the lines and, if necessary, make changes
bool putBestScore(const std::string& userName, int userScore)
{
	
	// Declaring this structãêó for storing player performance. Convenient for working with a file and sorting
	struct Performance
{
	std::string lineFromTheTable;
	std::string name;
	std::string str_score;
	int i_score;
} playerResults;


    const std::string highScoresFilename = "high_scores.txt";
	bool fileNeedsChanges = false,			// Flag of the presence of a player in the table.
		 playerFound = false,				// Player in file flag.
		 fileFound = false;					// If file isn't found - we need to create new.

	Performance *allResults = nullptr; 			// It's a pointer to a dynamic array that will be created after the lines in file are counted
	int numberOfPlayersInTheTable = 0;  		// The number of lines in the file, which corresponds to the number of players

	std::fstream fFile;
	fFile.open(highScoresFilename, std::ios_base::in | std::ios_base::ate);

	// As far as I know, resizing is a rather expensive operation. Therefore,
	// first we count the number of lines in the file, after which we create a dynamic array of a given size.
	if (fFile.is_open())
	{
		// Count the number of lines to know feature array size
		fFile.seekg(0, std::ios_base::beg);
		fileFound = true;
		while (true)
		{
			std::string forCount;
			std::getline(fFile, forCount);
			if (fFile.fail())
			{
				break;
			}
			++numberOfPlayersInTheTable;
		}
	
	// Create dynamic array with table date struct of each player
		allResults = new Performance[numberOfPlayersInTheTable];
		fFile.close();
		fFile.open(highScoresFilename, std::ios_base::in | std::ios_base::ate);
		fFile.seekg(0, std::ios_base::beg);		//I don't understand why, but this instruction don't work without reopening file :)

		// Read all lines from file
		for(int i = 0; i < numberOfPlayersInTheTable; i++)
		{
			std::getline(fFile, playerResults.lineFromTheTable);
			allResults[i] = playerResults;
			if (fFile.fail())
			{
				break;
			}
		}

		fFile.close();

		// Extract all variables from the lines and immediately check the presence of the player in the table
		bool spacerRead;
		for (int i = 0; i < numberOfPlayersInTheTable; i++)
		{
			spacerRead = false;
			for (auto symbol : allResults[i].lineFromTheTable)
			{
				if (symbol == '|')
				{
					spacerRead = true;
					continue; // To not include a separator in the name
				}

				if (spacerRead && symbol >= 48 && symbol <= 57)
				{
					allResults[i].str_score += symbol;
				}
				else
				{
					allResults[i].name += symbol;
				};
			}

			allResults[i].i_score = std::stoi(allResults[i].str_score);

			if (userName == allResults[i].name)
			{
				playerFound = true;
				if (userScore < allResults[i].i_score)
				{
					allResults[i].i_score = userScore;
					fileNeedsChanges = true;
				}
				else
				{
					break;
				}
			}
		}
	}

	// If file isn't found, creating a new one. If player in file isn't found - putting data at the end of the file.
	if (!playerFound || !fileFound)
	{
		fFile.open(highScoresFilename, std::ios_base::in | std::ios_base::out | std::ios_base::app);
		if (!fFile.is_open())
		{
			std::cout << "Failed to open file for write: " << highScoresFilename << "!" << std::endl;
			if (!allResults)
			{
				delete[] allResults;
				allResults = nullptr;
			}
			return false;
		}
		fFile << userName << "|" << userScore << std::endl;
	}
	else if (fileNeedsChanges) // If current score is better - making changes.
	{
		fFile.open(highScoresFilename, std::ios_base::out);
		if (!fFile.is_open())
		{
		std::cout << "Failed to open file for write: " << highScoresFilename << "!" << std::endl;
		delete[] allResults;
		allResults = nullptr;
		return false;
		}

		for (int i = 0; i < numberOfPlayersInTheTable; i++)
		{
			fFile << allResults[i].name << "|" << allResults[i].i_score << std::endl;
		}
	}

	fFile.close();
	if (!allResults)
	{
		delete[] allResults;
		allResults = nullptr;
	}

	return true;
}