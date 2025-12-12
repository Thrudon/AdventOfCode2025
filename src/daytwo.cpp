#include <iostream>

#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>

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

void DayTwo::SolvePartOne(std::string &result)
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
			
			// std::cerr << std::stoull(min) << " - " << val << " - " << std::stoull(max) << " : " << res << std::endl;
		}
	}
	file.close();

	result = std::to_string(res);
	return;
}

void DayTwo::SolvePartTwo(std::string &result)
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

		std::vector<std::string> testedValues;
		// Récupérer les n premiers chiffres
		for (unsigned long long n = 1; n <= max.size()/2; n++)
		{
			std::vector<unsigned long long> validSizes;
			std::vector<std::string> strMinVals;
			for (unsigned long long i = min.size(); i <= max.size(); i++)
			{
				if (i%n == 0 && i != n)
				{
					if (i == min.size())
						strMinVals.push_back(min.substr(0, n));
					else
					{
						std::string strMinVal = "1";
						for (unsigned long long i = 1; i < n; i++)
							strMinVal.append("0");
						strMinVals.push_back(strMinVal);
					}
					validSizes.push_back(i);
				}
			}

			if (validSizes.size() == 0)
				continue;

			for (unsigned int i = 0; i < validSizes.size(); i++)
			{
				for (unsigned long long val = std::stoull(strMinVals[i]); val <= std::stoull(validSizes[i] < max.size() ? std::string(n, '9') : max.substr(0, n)); val++)
				{
					std::string strVal;
					while (strVal.size() < validSizes[i])
						strVal.append(std::to_string(val));

					if (std::find(testedValues.begin(), testedValues.end(), strVal) == testedValues.end())
					{
						res += compareValToMinMax(std::stoull(min), std::stoull(max), std::stoull(strVal)) ? std::stoull(strVal) : 0;
						testedValues.push_back(strVal);
					}
				}
			}
		}
	}
	file.close();

	result = std::to_string(res);
	return;
}

bool DayTwo::compareValToMinMax(const unsigned long long &min, const unsigned long long &max, const unsigned long long &val)
{
	return (val >= min && val <= max);
}