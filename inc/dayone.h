#ifndef DAYONE_H
#define DAYONE_H

#include "exercice.h"

class DayOne : public Exercice
{
public:
	DayOne(char* &filepath);
	virtual ~DayOne();
	virtual void Solve(std::string &result, int &part);

protected:
	virtual void SolvePartOne(std::string &result, int &part);
	virtual void SolvePartTwo(std::string &result, int &part);

private: 
};

#endif