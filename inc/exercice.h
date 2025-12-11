#ifndef EXERCICE_H
#define EXERCICE_H

#include <string>

class Exercice
{
public:
	Exercice(char* &filepath);
	virtual ~Exercice();
	virtual void Solve(std::string &result, int &part) = 0;

protected:
	char* _filepath;

private: 
};

#endif