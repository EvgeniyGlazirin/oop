// ProcessVectorTests.cpp: ���������� ����� ����� ��� ����������� ����������.
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

