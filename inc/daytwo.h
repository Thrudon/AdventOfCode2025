#ifndef DAYTWO_H
#define DAYTWO_H

#include "exercice.h"

class DayTwo : public Exercice
{
public:
	DayTwo(char* &filepath);
	virtual ~DayTwo();
	virtual void Solve(std::string &result, int &part);

protected:
	virtual void SolvePartOne(std::string &result);
	virtual void SolvePartTwo(std::string &result);

private: 
	bool compareValToMinMax(const unsigned long long &min, const unsigned long long &max, const unsigned long long &val);
};

#endif