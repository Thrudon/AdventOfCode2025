#ifndef DAYTHREE_H
#define DAYTHREE_H

#include "exercice.h"

class DayThree : public Exercice
{
public:
	DayThree(char* &filepath);
	virtual ~DayThree();
	virtual void Solve(std::string &result, int &part);

protected:
	virtual void SolvePartOne(std::string &result);
	virtual void SolvePartTwo(std::string &result);

private:
	unsigned long long getJoltage(const std::string& batteryLine, int usableAmount);
};

#endif