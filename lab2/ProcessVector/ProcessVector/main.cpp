// ProcessVectorTests.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "ProcessVector.h"


int main()
{
	std::vector<double> inputNumbers = ReadVector(std::cin);
	ProcessVector(inputNumbers);
	//std::sort(inputNumbers.begin(), inputNumbers.end());
	PrintVector(std::cout, inputNumbers);
	return 0;
}

