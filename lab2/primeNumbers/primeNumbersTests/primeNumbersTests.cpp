// primeNumbersTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../primeNumbers/primeNumbers.h"

bool SetsAreEqual(const std::set<int> &firstSet, const std::set<int> &secondSet)
{
	return firstSet == secondSet;
}

TEST_CASE("function GeneratePrimeNumbersSet return all prime numbers until upper bound")
{
	CHECK(SetsAreEqual(GeneratePrimeNumbersSet(1), { }));
	CHECK(SetsAreEqual(GeneratePrimeNumbersSet(2), { 2 }));
	CHECK(SetsAreEqual(GeneratePrimeNumbersSet(11), { 2, 3, 5, 7, 11}));

}

#ifndef _DEBUG
TEST_CASE("function GeneratePrimeNumbersSet working right with max input value")
{
	std::set<int> checkResult = GeneratePrimeNumbersSet(100000000);
	CHECK(checkResult.size() == 5761455);
}
#endif