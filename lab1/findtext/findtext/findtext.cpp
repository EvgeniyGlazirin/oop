// findtext.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

bool PrintLineNumbersWhereSearchStringWasFound(std::ifstream &inputFile, std::string searchString)
{
	std::string line;
	bool stringWasFound = false;

	for (int numberOfLine = 1; std::getline(inputFile, line); ++numberOfLine)
	{
		auto pos = line.find(searchString);
		if (pos != std::string::npos)
		{
			std::cout << numberOfLine << "\n";
			stringWasFound = true;
		}
	}
	return stringWasFound;
}

int ResultOfSearchStringInFile(std::ifstream &inputFile, std::string searchString)
{
	if (!PrintLineNumbersWhereSearchStringWasFound(inputFile, searchString))
	{
		std::cout << "Search string was not found.\n";
		return 1;
	}
	return 0;
}


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid count of parameters. \n"
			<< "Usage: findtext.exe <inputFile> <searchString> \n";
		return 1;
	}

	std::ifstream inputFile;
	inputFile.open(argv[1]);
	if (!inputFile.is_open())
	{
		std::cout << "Failed to open " << argv[1] << " for reading \n";
		return 1;
	}

	std::string searchString;
	searchString = argv[2];

	if (searchString.empty())
	{
		std::cout << "Search string must be not empty. \n";
		return 1;
	}

    return ResultOfSearchStringInFile(inputFile, searchString);
}

