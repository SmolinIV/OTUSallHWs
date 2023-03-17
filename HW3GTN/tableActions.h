#pragma once
#include <iostream>

//Function prototypes:
// Print table
bool printTable();

// Put new player to the table "high_scores" or put better score of existing player
bool putBestScore(const std::string& name, int score);