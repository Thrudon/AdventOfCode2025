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
	virtual void SolvePartOne(std::string &result, int &part);
	virtual void SolvePartTwo(std::string &result, int &part);

private: 
};

#endif