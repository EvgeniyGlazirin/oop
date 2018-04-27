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
			primeNumbers.insert(primeNumbers.end(), static_cast<int>(i));
		}
	}
	return primeNumbers;
}

void EratosthenesSieve(std::vector<bool> &sieve)
{
	for (int i = 2; i * i < sieve.size(); i++)
	{
		if (sieve[i])
		{
			for (int j = i * i; j < sieve.size(); j += i)
			{
				sieve[j] = false;
			}
		}
	}
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::vector<bool> sieve(upperBound + 1 , true);
	EratosthenesSieve(sieve);
	std::set<int> primeNumbers = GetPrimeNumbers(sieve);
	return primeNumbers;
}