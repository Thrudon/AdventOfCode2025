#ifndef DAYFOUR_H
#define DAYFOUR_H

#include <vector>

#include "exercice.h"

class DayFour : public Exercice
{
public:
	DayFour(char* &filepath);
	virtual ~DayFour();
	virtual void solve(std::string &result, int &part);

protected:
	virtual void solvePartOne(std::string &result);
	virtual void solvePartTwo(std::string &result);

private: 
	int removeRolls(std::vector<std::string> &wall);
};

#endif