#ifndef DAYONE_H
#define DAYONE_H

#include "exercice.h"

class DayOne : public Exercice
{
public:
	DayOne(char* &filepath);
	virtual ~DayOne();
	virtual void solve(std::string &result, int &part);

protected:
	virtual void solvePartOne(std::string &result);
	virtual void solvePartTwo(std::string &result);

private: 
};

#endif