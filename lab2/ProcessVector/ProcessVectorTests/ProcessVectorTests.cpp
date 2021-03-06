// MultOnMinElementTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../ProcessVector/ProcessVector.h"

bool VectorsAreEqual(const std::vector<double> &input, const std::vector<double> &output)
{
	return input == output;
}

TEST_CASE("function ProcessVector for empty vector is change nothing")
{
	std::vector<double> testVector = { };
	ProcessVector(testVector);
	CHECK(VectorsAreEqual(testVector, { }));
}

TEST_CASE("function ProcessVector is multiply vector elements on a minimal element of that vector")
{
	std::vector<double> testVector = { 2, 10, 11.1 };
	ProcessVector(testVector);
	CHECK(VectorsAreEqual(testVector, { 4, 20, 22.2 }));
}
