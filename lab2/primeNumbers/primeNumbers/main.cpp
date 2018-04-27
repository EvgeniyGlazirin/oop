#include "stdafx.h"

const int maxValueNumber = 100000000;
const int minValueNumber = 2;

bool IsUpperBoundCorrect(int upperBound)
{
	return(upperBound >= minValueNumber && upperBound <= maxValueNumber);
}

void PrintPrimeNumbers(std::ostream& output, const std::set<int>& primeNumbers)
{
	std::copy(primeNumbers.begin(), primeNumbers.end(), std::ostream_iterator<int>(output, " "));
	output << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid count of parameters." << std::endl <<
			"Usage primeNumbers.exe <upper bound value>" << std::endl;
		return 1;
	}

	int upperBound;
	try
	{
		upperBound = std::stoi(argv[1]);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	if (!IsUpperBoundCorrect(upperBound))
	{
		std::cout << "Incorrect value of upper bound. It should be from 2 to 100000000."
			<< std::endl;
		return 1;
	}
	
	boost::timer time;
	time.restart();
	std::set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound);
	PrintPrimeNumbers(std::cout, primeNumbers);
	
	std::cout << "Elapsed time " << time.elapsed() << std::endl;
	return 0;
}
