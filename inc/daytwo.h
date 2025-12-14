#ifndef DAYTWO_H
#define DAYTWO_H

#include "exercice.h"

class DayTwo : public Exercice
{
public:
	DayTwo(char* &filepath);
	virtual ~DayTwo();
	virtual void solve(std::string &result, int &part);

protected:
	virtual void solvePartOne(std::string &result);
	virtual void solvePartTwo(std::string &result);

private: 
};

#endif