#include <iostream>

#include <fstream>
#include <sstream>
#include <cstring>

#include "../inc/dayfour.h"

DayFour::DayFour(char* &filepath) :
	Exercice(filepath)
{}

DayFour::~DayFour()
{}

void DayFour::Solve(std::string &result, int &part)
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

void DayFour::SolvePartOne(std::string &result)
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
		;
	}
	file.close();

	result = std::to_string(res);
	return;
}

void DayFour::SolvePartTwo(std::string &result)
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
		;
	}
	file.close();

	result = std::to_string(res);
	return;
}