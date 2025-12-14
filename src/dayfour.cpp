#include <iostream>

#include <fstream>
#include <sstream>

#include "../inc/dayfour.h"

DayFour::DayFour(char* &filepath) :
	Exercice(filepath)
{}

DayFour::~DayFour()
{}

void DayFour::solve(std::string &result, int &part)
{
	switch(part)
	{
	case 1:
		solvePartOne(result);
		break;
	case 2:
		solvePartTwo(result);
		break;
	default:
		result = "Invalid part !";
	}
	return;
}

void DayFour::solvePartOne(std::string &result)
{
	std::ifstream file(_filepath);
	if (!file)
	{
		result = "Couldn't open file !";
		return;
	}

	std::vector<std::string> lines;
	std::string line;
	while (std::getline(file, line))
	{
		lines.push_back(line);
	}
	file.close();

	result = std::to_string(removeRolls(lines));
	return;
}

void DayFour::solvePartTwo(std::string &result)
{
	std::ifstream file(_filepath);
	if (!file)
	{
		result = "Couldn't open file !";
		return;
	}

	std::vector<std::string> lines;
	std::string line;
	while (std::getline(file, line))
	{
		lines.push_back(line);
	}
	file.close();

	int res = 0;
	int removedRolls = 0;
	do
	{
		removedRolls = removeRolls(lines);
		res += removedRolls;
	} while (removedRolls != 0);

	result = std::to_string(res);
}

int DayFour::removeRolls(std::vector<std::string> &wall)
{
	int removedRolls = 0;
	std::vector<std::vector<unsigned long long>> pos;
	for (unsigned long long i = 0; i < wall.size(); i++)
	{
		for (unsigned long long j = 0; j < wall[i].size(); j++)
		{
			if (wall[i].at(j) != '@')
				continue;

			int neighbourRolls = 0;
			// Previous Line
			if (i > 0)
			{
				if (j > 0)
					neighbourRolls += wall[i-1][j-1] == '@' ? 1 : 0;
				neighbourRolls += wall[i-1][j] == '@' ? 1 : 0;
				if (j < wall[i-1].size() - 1)
					neighbourRolls += wall[i-1][j+1] == '@' ? 1 : 0;
			}
			// Current Line
			if (j > 0)
				neighbourRolls += wall[i][j-1] == '@' ? 1 : 0;
			if (j < wall[i].size() - 1)
				neighbourRolls += wall[i][j+1] == '@' ? 1 : 0;

			// Next Line
			if (i < wall.size() - 1)
			{
				if (j > 0)
					neighbourRolls += wall[i+1][j-1] == '@' ? 1 : 0;
				neighbourRolls += wall[i+1][j] == '@' ? 1 : 0;
				if (j < wall[i+1].size() - 1)
					neighbourRolls += wall[i+1][j+1] == '@' ? 1 : 0;
			}

			if (neighbourRolls < 4)
			{
				removedRolls++;
				pos.push_back(std::vector<unsigned long long>{i, j});
			}
		}
	}

	for (unsigned int i = 0; i < pos.size(); i++)
		wall[pos[i][0]][pos[i][1]] = 'x';

	return removedRolls;
}