#ifndef DAYFIVE_H
#define DAYFIVE_H

#include <vector>

#include "exercice.h"

struct Range
{
	unsigned long long min;
	unsigned long long max;

	bool operator<(const Range &rhs)
	{
		return min == rhs.min ? max < rhs.max : min < rhs.min;
	}
};

class DayFive : public Exercice
{
public:
	DayFive(char* &filepath);
	virtual ~DayFive();
	virtual void solve(std::string &result, int &part);

protected:
	virtual void solvePartOne(std::string &result);
	virtual void solvePartTwo(std::string &result);

private: 
	std::vector<Range> handleRangeOverlap(std::vector<Range> ranges);
};

#endif