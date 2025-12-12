#include <iostream>

#include <fstream>
#include <sstream>
#include <cstring>

#include "../inc/dayone.h"

DayOne::DayOne(char* &filepath) :
	Exercice(filepath)
{}

DayOne::~DayOne()
{}

void DayOne::Solve(std::string &result, int &part)
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

void DayOne::SolvePartOne(std::string &result)
{
	std::ifstream file(_filepath);
	if (!file)
	{
		result = "Couldn't open file !";
		return;
	}

	int pos = 50;
	int res = 0;

	std::string line;
	while (std::getline(file, line))
	{
		pos += line.substr(0, 1) == "R" ? std::stoi(line.substr(1)) : -std::stoi(line.substr(1));
		pos %= 100;
		if (pos == 0)
			res++;
	}
	file.close();

	result = std::to_string(res);
	return;
}

void DayOne::SolvePartTwo(std::string &result)
{
	std::ifstream file(_filepath);
	if (!file)
	{
		result = "Couldn't open file !";
		return;
	}

	int pos = 50;
	int res = 0;

	std::string line;
	while (std::getline(file, line))
	{
		std::cerr << line << " - " << pos << " - " << res << std::endl;
		int val = std::stoi(line.substr(1));
		if (line.substr(0, 1) == "R")
		{
			if (pos < 0 && pos + val % 100 >= 0)
				res++;
			if (pos > 0 && pos + val % 100 >= 100)
				res++;
			pos += val % 100;
		}
		if (line.substr(0, 1) == "L")
		{
			if (pos < 0 && pos - val % 100 <= -100)
				res++;
			if (pos > 0 && pos - val % 100 <= 0)
				res++;
			pos -= val % 100;
		}
		pos %= 100;
		res += val / 100;
	}
	file.close();

	result = std::to_string(res);
	return;
}