#ifndef DAYTHREE_H
#define DAYTHREE_H

#include "exercice.h"

class DayThree : public Exercice
{
public:
	DayThree(char* &filepath);
	virtual ~DayThree();
	virtual void solve(std::string &result, int &part);

protected:
	virtual void solvePartOne(std::string &result);
	virtual void solvePartTwo(std::string &result);

private:
	std::string getJoltage(const std::string& batteryLine, int usableAmount);
};

#endif