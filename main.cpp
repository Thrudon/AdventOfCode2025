#include <iostream>
#include <cstring>
#include <string>

#include "inc/dayone.h"
#include "inc/daytwo.h"
#include "inc/daythree.h"
#include "inc/dayfour.h"

int main(int argc, char* argv[])
{
	int day = 1;
	int part = 1;
	char* filepath = NULL;

	// std::cerr << "Argc: " << argc << std::endl;
	// for (int i = 0; i < argc; i++)
	// 	std::cerr << "Arg " << i << " : " << argv[i] << std::endl;

	switch (argc)
	{
	case 4:
		part = std::stoi(argv[argc-2]);
		[[fallthrough]];
	case 3:
		day = std::stoi(argv[argc-3]);
		[[fallthrough]];
	case 2:
		filepath = argv[argc-1];
		break;
	default:
		std::cerr << "No file given." << std::endl;
		return 1;
	}

	if (strcmp(filepath, "help") == 0)
	{
		std::cout << "./bin/AOC.exe <Day> <Part> <Filepath>";
		return 0;
	}

	Exercice* currentEx = NULL;
	switch (day)
	{
	case 1:
		currentEx = new DayOne(filepath);
		break;
	case 2:
		currentEx = new DayTwo(filepath);
		break;
	case 3:
		currentEx = new DayThree(filepath);
		break;
	case 4:
		currentEx = new DayFour(filepath);
		break;
	}

	if (!currentEx)
	{
		std::cerr << "Exercice inexistant." << std::endl;
		return 1;
	}

	std::string result;
	currentEx->Solve(result, part);

	std::cout << "Resultat : " << result << std::endl;
	// std::cerr << "Jour " << day << " - Partie " << part << " - Fichier: " << filepath << std::endl;

	delete currentEx;
	return 0;
}