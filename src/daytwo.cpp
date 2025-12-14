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

		std::string borneMin = min.substr(0, (min.size()/2 == 0 ? 1 : min.size()/2));
		std::string borneMax = max.substr(0, (max.size() % 2 ? max.size()/2 + 1: max.size()/2));

		for (std::string val = borneMin; (val.size() < borneMax.size() || std::strcmp(val.c_str(), borneMax.c_str()) <= 0); incrStrVal(val))
		{
			std::string strVal = val;
			strVal.append(val);

			if (strVal.size() < min.size() || (std::strcmp(strVal.c_str(), min.c_str()) < 0 && strVal.size() == min.size()))
				continue;
			if (strVal.size() > max.size() || (std::strcmp(strVal.c_str(), max.c_str()) > 0 && strVal.size() == max.size()))
				break;
			res += std::stoull(strVal);
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

	// old - 17298174201
	// cur - 13802501794

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
				for (std::string val = strMinVals[i]; val.size() <= (validSizes[i] < max.size() ? std::string(n, '9') : max.substr(0, n)).size() && std::strcmp(val.c_str(), (validSizes[i] < max.size() ? std::string(n, '9') : max.substr(0, n)).c_str()) <= 0; incrStrVal(val))
				{
					std::string strVal = val;
					while (strVal.size() < validSizes[i])
						strVal.append(val);

					if (std::find(testedValues.begin(), testedValues.end(), strVal) == testedValues.end())
					{
						res += ((strVal.size() > min.size() || std::strcmp(strVal.c_str(), min.c_str()) >= 0) && (strVal.size() < max.size() || std::strcmp(strVal.c_str(), max.c_str()) <= 0)) ? std::stoull(strVal) : 0;
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

void DayTwo::incrStrVal(std::string &strVal, int incr)
{
	std::string::reverse_iterator it = strVal.rbegin();
	while (incr && it != strVal.rend())
	{
		int value = (*it - '0') + incr;
		incr = value / 10;
		*it = '0' + (value % 10);
		++it;
	}
	if (incr)
		strVal.insert(0, "1");
}