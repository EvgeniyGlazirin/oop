// lab00.3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		std::cout << "Invalid count of parameters \n";
		return 1;
	}


	int lastNumber = 0;
	int currentNumber = 1;
	int maxElement = std::stoi(argv[1]);
	int countNumbers = 1;
	int maxCountInRow = 5;

	while (currentNumber < maxElement)
	{


		std::cout << currentNumber;

		if (countNumbers % maxCountInRow == 0)
		{
			std::cout << ", \n";

		}
		else {
			std::cout << ", ";
		}

		currentNumber = currentNumber + lastNumber;
		lastNumber = currentNumber - lastNumber;
		countNumbers += 1;
	}

	std::cout << "\n";
    return 0;
}

