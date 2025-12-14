#include <iostream>

#include <fstream>
#include <sstream>

#include "../inc/daythree.h"

DayThree::DayThree(char* &filepath) :
	Exercice(filepath)
{}

DayThree::~DayThree()
{}

void DayThree::solve(std::string &result, int &part)
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

void DayThree::solvePartOne(std::string &result)
{
	std::ifstream file(_filepath);
	if (!file)
	{
		result = "Couldn't open file !";
		return;
	}

	result = "0";

	std::string line;
	while (std::getline(file, line))
	{
		result = addStrings(result, getJoltage(line, 2));
	}
	file.close();
}

void DayThree::solvePartTwo(std::string &result)
{
	std::ifstream file(_filepath);
	if (!file)
	{
		result = "Couldn't open file !";
		return;
	}

	result = "0";

	std::string line;
	while (std::getline(file, line))
	{
		result = addStrings(result, getJoltage(line, 12));
	}
	file.close();
}

std::string DayThree::getJoltage(const std::string& batteryLine, int usableAmount)
{
	std::string joltages = batteryLine.substr(batteryLine.size() - usableAmount);

	for (int i = batteryLine.size() - (usableAmount + 1); i >= 0; i--)
	{
		char swap = batteryLine[i];
		for (unsigned long long j = 0; j < joltages.size(); j++)
		{
			if (swap >= joltages[j])
			{
				char temp = joltages[j];
				joltages[j] = swap;
				swap = temp;
			}
			else
				break;
		}
	}

	return joltages;
}