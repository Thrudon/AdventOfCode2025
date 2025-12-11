#include <iostream>

#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

#include "../inc/daytwo.h"

DayTwo::DayTwo(char* &filepath) :
	Exercice(filepath)
{}

DayTwo::~DayTwo()
{}

void DayTwo::Solve(std::string &result, int &part)
{
	switch(part)
	{
	case 1:
		SolvePartOne(result, part);
		break;
	case 2:
		SolvePartTwo(result, part);
		break;
	default:
		result = "Invalid part !";
	}
	return;
}

void DayTwo::SolvePartOne(std::string &result, int &part)
{
	std::ifstream file(_filepath);
	if (!file)
	{
		result = "Couldn't open file !";
		return;
	}

	unsigned long long res = 0;

	std::string line;
	while (std::getline(file, line, ','))
	{
		std::string min = line.substr(0, line.find("-"));
		std::string max = line.substr(line.find("-") + 1);

		if (min.size() % 2 && min.size() == max.size())
			continue;

		int borneMin = std::stoi(min.substr(0, (min.size()/2 == 0 ? 1 : min.size()/2)));
		int borneMax = std::stoi(max.substr(0, (max.size() % 2 ? max.size()/2 + 1: max.size()/2)));

		for (int i = borneMin; i <= borneMax; i++)
		{
			std::string strVal = std::to_string(i);
			strVal.append(std::to_string(i));
			unsigned long long val = std::stoull(strVal);

			if (val < std::stoull(min))
				continue;
			if (val > std::stoull(max))
				break;
			if (val >= std::stoull(min) && val <= std::stoull(max))
				res += val;
			
			std::cerr << std::stoull(min) << " - " << val << " - " << std::stoull(max) << " : " << res << std::endl;
		}
	}
	file.close();

	result = std::to_string(res);
	return;
}

void DayTwo::SolvePartTwo(std::string &result, int &part)
{
	std::ifstream file(_filepath);
	if (!file)
	{
		result = "Couldn't open file !";
		return;
	}

	std::string line;
	while (std::getline(file, line, ','))
	{
		;
	}
	file.close();

	// Idée :
	/* Récupérer le premier n-ième du min (moitié, tiers, quart, etc.)
	 * et le dupliquer n fois puis comparer, incrémenter, etc.
	 */

	result = std::to_string(2);
	return;
}