#include "../inc/exercice.h"

Exercice::Exercice(char* &filepath) :
	_filepath(filepath)
{}

Exercice::~Exercice()
{
	delete _filepath;
}