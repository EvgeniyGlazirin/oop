// primeNumbers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "primeNumbers.h"

std::set<int> GetPrimeNumbers(const std::vector<bool>& sieve)
{
	std::set<int> primeNumbers;
	for (int i = 2; i < sieve.size(); i++)
	{
		if (sieve[i])
		{
			primeNumbers.insert(primeNumbers.end(), i);
		}
	}
	return primeNumbers;
}

void ExcludeMultipliesOf(int i, std::vector<bool> &isPrime)
{
	for (int j = i * i; j < isPrime.size(); j += i)
	{
		isPrime[j] = false;
	}
}

void FindPrimeNumbersThroughEratosthenesSieve(std::vector<bool> &isPrime)
{
	for (int i = 2; i * i < isPrime.size(); i++)
	{
		if (isPrime[i])
		{
			ExcludeMultipliesOf(i, isPrime);
		}
	}
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::vector<bool> sieve(upperBound + 1 , true);
	FindPrimeNumbersThroughEratosthenesSieve(sieve);
	std::set<int> primeNumbers = GetPrimeNumbers(sieve);
	return primeNumbers;
}