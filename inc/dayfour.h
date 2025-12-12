#ifndef DAYFOUR_H
#define DAYFOUR_H

#include "exercice.h"

class DayFour : public Exercice
{
public:
	DayFour(char* &filepath);
	virtual ~DayFour();
	virtual void Solve(std::string &result, int &part);

protected:
	virtual void SolvePartOne(std::string &result);
	virtual void SolvePartTwo(std::string &result);

private: 
};

#endif