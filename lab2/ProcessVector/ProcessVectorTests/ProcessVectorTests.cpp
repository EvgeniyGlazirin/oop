// MultOnMinElementTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../ProcessVector/ProcessVector.h"



bool VectorsAreEqual(std::vector<double> const &input, const std::vector<double> const &output)
{
	return input == output;
}


TEST_CASE("empty vector remains empty vector")
{
	std::vector<double> testVector = { };
	CHECK(VectorsAreEqual(testVector, { }));
}


TEST_CASE("result multyplay by 0 remains ")
{

	std::vector<double> testVector = { 2, 10, 11.1 };
	ProcessVector(testVector);
	CHECK(VectorsAreEqual(testVector, { 4, 20, 22.2 }));
}

TEST_CASE("result ProcessVector equal expected result")
{

	std::vector<double> testVector = { 2, 10, 11.1 };
	ProcessVector(testVector);
	CHECK(VectorsAreEqual(testVector, { 4, 20, 22.2 }));
}

