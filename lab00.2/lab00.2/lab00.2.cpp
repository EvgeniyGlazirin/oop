// lab00.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int SumDigits(int i)
{
	int sum = 0;

	while (i != 0)
	{
		sum += i % 10;
		i /= 10;
 	}

	return sum;
}

void findNumbers(const int maxNumberByUser)
{
	for (int i = 1; i <= maxNumberByUser; ++i)
	{
		if (i % SumDigits(i) == 0)
		{
			std::cout << i << ' ';
		}
	}
	std::cout << '\n';
}

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		const int maxNumberByUser = std::stoi(argv[1]);
		if (maxNumberByUser >= 1)
		{
			findNumbers(maxNumberByUser);
		}
		else {
			std::cout << "Argument must be >= 1 \n";
			return 1;
		}
	}
	else {
		std::cout << "Invalid count of parameters \n";
		return 1;
	}

    return 0;
}

