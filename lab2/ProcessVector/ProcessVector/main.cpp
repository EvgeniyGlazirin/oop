// ProcessVectorTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int main()
{
	std::vector<double> inputNumbers = ReadVector(std::cin);
	ProcessVector(inputNumbers);
	std::sort(inputNumbers.begin(), inputNumbers.end());
	PrintVector(std::cout, inputNumbers);
	return 0;
}
