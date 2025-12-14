#include <iostream>

#include <fstream>
#include <sstream>
#include <algorithm>

#include "../inc/dayfive.h"

DayFive::DayFive(char* &filepath) :
	Exercice(filepath)
{}

DayFive::~DayFive()
{}

void DayFive::solve(std::string &result, int &part)
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

void DayFive::solvePartOne(std::string &result)
{
	std::ifstream file(_filepath);
	if (!file)
	{
		result = "Couldn't open file !";
		return;
	}

	std::vector<Range> ranges;
	std::string line;
	// Loop through ranges
	while (std::getline(file, line))
	{
		if (line.empty())
			break;

		unsigned long long min = std::stoull(line.substr(0, line.find('-')));
		unsigned long long max = std::stoull(line.substr(line.find('-') + 1));
		ranges.push_back({min, max});
	}
	ranges = handleRangeOverlap(ranges);

	// Loop through IDs
	int freshIDAmt = 0;
	while (std::getline(file, line))
	{
		unsigned long long ingID = std::stoull(line);
		std::cerr << line << " - " << ingID << std::endl;
		for (std::size_t i = 0; i < ranges.size(); i++)
		{
			if (ranges[i].max < ingID)
				continue;

			if (ranges[i].min <= ingID)
				freshIDAmt++;

			std::cerr << ranges[i].min << ":" << ranges[i].max << " - " << ingID << " : " << freshIDAmt << std::endl;
			break;
		}
	}
	file.close();

	result = std::to_string(freshIDAmt);
}

void DayFive::solvePartTwo(std::string &result)
{
	std::ifstream file(_filepath);
	if (!file)
	{
		result = "Couldn't open file !";
		return;
	}

	std::vector<Range> ranges;
	std::string line;
	// Loop through ranges
	while (std::getline(file, line))
	{
		if (line.empty())
			break;

		unsigned long long min = std::stoull(line.substr(0, line.find('-')));
		unsigned long long max = std::stoull(line.substr(line.find('-') + 1));
		ranges.push_back({min, max});
	}
	ranges = handleRangeOverlap(ranges);

	unsigned long long res = 0;
	for (std::size_t i = 0; i < ranges.size(); i++)
		res += (ranges[i].max - ranges[i].min) + 1;

	file.close();

	result = std::to_string(res);
}

std::vector<Range> DayFive::handleRangeOverlap(std::vector<Range> ranges)
{
	std::sort(ranges.begin(), ranges.end());

	std::vector<Range> result;
	Range current = ranges[0];
	
	for (std::size_t i = 1; i < ranges.size(); i++)
	{
		if (current.max >= ranges[i].min - 1)
			current.max = ranges[i].max > current.max ? ranges[i].max : current.max;
		else
		{
			result.push_back(current);
			current = ranges[i];
		}
	}
	result.push_back(current);

	return result;
}