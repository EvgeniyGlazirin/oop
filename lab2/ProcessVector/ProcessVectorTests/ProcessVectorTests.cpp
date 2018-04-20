// MultOnMinElementTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../ProcessVector/ProcessVector.h"

bool VectorsAreEqual(const std::vector<double> &input, const std::vector<double> &output)
{
	return input == output;
}

TEST_CASE("process for empty vector is change nothing")
{
	std::vector<double> testVector = { };
	CHECK(VectorsAreEqual(testVector, { }));
}

TEST_CASE("found minimul number in vector was right")
{
	std::vector<double> testVector = { 2, -2, 11.1 };
	const double minElementOfVector = *std::min_element(testVector.begin(), testVector.end());
	CHECK(-2 == minElementOfVector);
}

TEST_CASE("function ProcessVector with negative minimum number gives expected result")
{
	std::vector<double> testVector = { 2, -2, 11.1 };
	ProcessVector(testVector);
	CHECK(VectorsAreEqual(testVector, { -4, 4, -22.2 }));
}

TEST_CASE("function ProcessVector gives expected result")
{

	std::vector<double> testVector = { 2, 10, 11.1 };
	ProcessVector(testVector);
	CHECK(VectorsAreEqual(testVector, { 4, 20, 22.2 }));
}

TEST_CASE("fuction ProcessVector and sort gives expected result")
{

	std::vector<double> testVector = { 2, 10, 9 };
	ProcessVector(testVector);
	std::sort(testVector.begin(), testVector.end());
	CHECK(VectorsAreEqual(testVector, { 4, 18, 20 }));
}