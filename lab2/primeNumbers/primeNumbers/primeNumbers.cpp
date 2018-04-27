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

void ExcludeMultipliesOf(int i, std::vector<bool> &isPrime)
{
	int step = 1;
	if (step == 1)
	{
		for (int j = i * i; j < isPrime.size(); j += i)
		{
			isPrime[j] = false;
			step += 1;
		}
	}
	else
	{
		for (int j = i * i; j < isPrime.size(); j += 2 * i)
		{
			isPrime[j] = false;
		}
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