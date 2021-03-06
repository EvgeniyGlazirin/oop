// primeNumbers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "primeNumbers.h"

std::set<int> GetPrimeNumbers(const std::vector<bool>& isPrime)
{
	std::set<int> primeNumbers;
	for (int i = 2; i < isPrime.size(); i++)
	{
		if (isPrime[i])
		{
			primeNumbers.emplace_hint(primeNumbers.end(), i);
		}
	}
	return primeNumbers;
}

void FindPrimeNumbersThroughEratosthenesSieve(std::vector<bool> &isPrime)
{
	int step = 1;
	for (int i = 2; i * i < isPrime.size(); i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < isPrime.size(); j += i * step)
			{
				isPrime[j] = false;
			}
		}
		step = 2;
	}
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::vector<bool> sieve(upperBound + 1 , true);
	FindPrimeNumbersThroughEratosthenesSieve(sieve);
	std::set<int> primeNumbers = GetPrimeNumbers(sieve);
	return primeNumbers;
}