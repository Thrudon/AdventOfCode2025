#ifndef DAYTWO_H
#define DAYTWO_H

#include <cstring>

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
	void incrStrVal(std::string &strVal, int incr = 1);
};

#endif