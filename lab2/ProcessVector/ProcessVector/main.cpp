// ProcessVectorTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	std::vector<double> inputNumbers;
	ReadVector(std::cin, inputNumbers);
	ProcessVector(inputNumbers);
	PrintVector(std::cout, inputNumbers);
	return 0;
}

