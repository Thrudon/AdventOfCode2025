#include <iostream>

#include <fstream>
#include <sstream>
#include <cstring>

#include "../inc/daythree.h"

DayThree::DayThree(char* &filepath) :
	Exercice(filepath)
{}

DayThree::~DayThree()
{}

void DayThree::Solve(std::string &result, int &part)
{
	switch(part)
	{
	case 1:
		SolvePartOne(result);
		break;
	case 2:
		SolvePartTwo(result);
		break;
	default:
		result = "Invalid part !";
	}
	return;
}

void DayThree::SolvePartOne(std::string &result)
{
	std::ifstream file(_filepath);
	if (!file)
	{
		result = "Couldn't open file !";
		return;
	}

	unsigned long long res = 0;

	std::string line;
	while (std::getline(file, line))
	{
		res += getJoltage(line, 2);
	}
	file.close();

	result = std::to_string(res);
	return;
}

void DayThree::SolvePartTwo(std::string &result)
{
	std::ifstream file(_filepath);
	if (!file)
	{
		result = "Couldn't open file !";
		return;
	}

	unsigned long long res = 0;

	std::string line;
	while (std::getline(file, line))
	{
		res += getJoltage(line, 12);
	}
	file.close();

	result = std::to_string(res);
	return;
}

unsigned long long DayThree::getJoltage(const std::string& batteryLine, int usableAmount)
{
	std::string joltages = batteryLine.substr(batteryLine.size() - usableAmout);

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

	return std::stoull(joltages);
}