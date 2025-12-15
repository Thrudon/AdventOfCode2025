#include <iostream>

#include <fstream>
#include <sstream>
#include <algorithm>

#include "../inc/daysix.h"

DaySix::DaySix(char* &filepath) :
	Exercice(filepath)
{}

DaySix::~DaySix()
{}

void DaySix::solve(std::string &result, int &part)
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

void DaySix::solvePartOne(std::string &result)
{
	std::ifstream file(_filepath);
	if (!file)
	{
		result = "Couldn't open file !";
		return;
	}

	result = "0";
	std::vector<std::vector<unsigned long long>> table;

	std::string line;
	while (std::getline(file, line))
	{
		unsigned int col = 0;
		std::size_t start = 0;
		if (line.find_first_of("0123456789") != std::string::npos)
		{
			while (start < line.size())
			{
				std::size_t pos = line.substr(start).find_first_of(' ');
				pos = (pos == std::string::npos) ? line.size() : (pos ? pos : 1);
				std::string val = line.substr(start, pos);
				if (val.find_first_of(' ') == std::string::npos)
				{
					if (table.size() <= col)
						table.push_back({std::stoull(val)});
					else
						table[col].push_back(std::stoull(val));
					col++;
				}
				start += pos;
			}
		}
		else
		{
			while (start < line.size())
			{
				std::size_t pos = line.find_first_of(' ');
				pos = (pos == std::string::npos) ? line.size() : (pos ? pos : 1);
				std::string val = line.substr(start, pos);
				if (val.find_first_of(' ') == std::string::npos)
				{
					switch (val[0])
					{
					case '*':
					{
						unsigned long long res = 1;
						for (std::size_t i = 0; i < table[col].size(); i++)
							res *= table[col][i];
						result = addStrings(result, std::to_string(res));
						break;
					}
					case '+':
					{
						unsigned long long res = 0;
						for (std::size_t i = 0; i < table[col].size(); i++)
							res += table[col][i];
						result = addStrings(result, std::to_string(res));
						break;
					}
					}
					col++;
				}
				start += pos;
			}
		}
	}
	file.close();
}

void DaySix::solvePartTwo(std::string &result)
{
	std::ifstream file(_filepath);
	if (!file)
	{
		result = "Couldn't open file !";
		return;
	}

	result = "0";
	std::vector<std::string> numbers;

	std::string line;
	std::string operators;
	while (std::getline(file, line))
	{
		std::reverse(line.begin(), line.end());
		if (line.find_first_of("0123456789") != std::string::npos)
			numbers.push_back(line);
		else
			operators = line;
	}

	numbers = transposeStrings(numbers);

	for (std::string& number : numbers)
	{
		std::string::iterator spacePos = std::find(number.begin(), number.end(), ' ');
		while (spacePos != number.end())
		{
			number.erase(std::find(number.begin(), number.end(), ' '));
			spacePos = std::find(number.begin(), number.end(), ' ');
		}
	}

	std::size_t start = 0;
	for (std::size_t i = 0; i < operators.size(); i++)
	{
		if (numbers[i].empty())
		{
			start = i + 1;
			continue;
		}
		switch (operators[i])
		{
		case '*':
		{
			unsigned long long res = 1;
			for (std::size_t j = start; j <= i; j++)
				res *= std::stoull(numbers[j]);
			result = addStrings(result, std::to_string(res));
			break;
		}
		case '+':
		{
			unsigned long long res = 0;
			for (std::size_t j = start; j <= i; j++)
				res += std::stoull(numbers[j]);
			result = addStrings(result, std::to_string(res));
			break;
		}
		}
	}

	file.close();
}

std::vector<std::string> DaySix::transposeStrings(const std::vector<std::string> &strings)
{
	std::vector<std::string> transpose;
	for(std::size_t i = 0; i < strings.size(); i++)
	{
		for (std::size_t j = 0; j < strings[i].size(); j++)
		{
			if (transpose.size() <= j)
			{
				transpose.push_back(std::string());
				transpose[j].reserve(strings.size());
			}
			transpose[j].push_back(strings[i][j]);
		}
	}
	return transpose;
}