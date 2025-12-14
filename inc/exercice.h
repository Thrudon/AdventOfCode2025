#ifndef EXERCICE_H
#define EXERCICE_H

#include <string>

class Exercice
{
public:
	Exercice(char* &filepath);
	virtual ~Exercice();
	virtual void solve(std::string &result, int &part) = 0;

protected:
	char* _filepath;

	virtual void solvePartOne(std::string &result) = 0;
	virtual void solvePartTwo(std::string &result) = 0;
	std::string addStrings(const std::string &str1, const std::string &str2);

private: 
};

#endif