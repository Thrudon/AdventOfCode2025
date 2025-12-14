#include <iostream>
#include <algorithm>

#include "../inc/exercice.h"

Exercice::Exercice(char* &filepath) :
	_filepath(filepath)
{}

Exercice::~Exercice()
{
	delete _filepath;
}

std::string Exercice::addStrings(const std::string &str1, const std::string &str2)
{
    const int str1Size = str1.size();
    const int str2Size = str2.size();

    const std::string& minString = str1Size < str2Size ? str1 : str2;
    const int minSize = str1Size < str2Size ? str1Size : str2Size;

    const std::string& maxString = str2Size > str1Size ? str2 : str1;
    const int maxSize = str2Size > str1Size ? str2Size : str1Size;

    std::string result;
    result.reserve(maxSize + 1);

    int carry = 0;

    for (int i = 0; i < maxSize; ++i) {
        const int a = i < minSize ? minString[minSize - i - 1] - '0' : 0;
        const int b = maxString[maxSize - i - 1] - '0';
        const int sum = a + b + carry;

        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry != 0)
        result.push_back(carry + '0');

    std::reverse(result.begin(), result.end());
    return result;
}