#ifndef DAYSIX_H
#define DAYSIX_H

#include <vector>

#include "exercice.h"

class DaySix : public Exercice
{
public:
	DaySix(char* &filepath);
	virtual ~DaySix();
	virtual void solve(std::string &result, int &part);

protected:
	virtual void solvePartOne(std::string &result);
	virtual void solvePartTwo(std::string &result);

private:
	std::vector<std::string> transposeStrings(const std::vector<std::string> &strings);
};

#endif