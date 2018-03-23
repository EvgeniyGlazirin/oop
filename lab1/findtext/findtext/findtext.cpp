// findtext.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

enum result
{
	text_was_found,
	text_not_found,
	err
};

result PrintLineNumbersContainingText(const std::string &inputFile, std::string searchString)
{
	std::string line;
	std::ifstream file;
	file.open(inputFile);
	if (!file.is_open())
	{
		return err;
	}

	bool stringWasFound = false;
	for (int numberOfLine = 1; std::getline(file, line); ++numberOfLine)
	{
		auto pos = line.find(searchString);
		if (pos != std::string::npos)
		{
			std::cout << numberOfLine << "\n";
			stringWasFound = true;
		}
	}

	if (stringWasFound)
	{
		return text_was_found;
	} 
	else
	{
		return text_not_found;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid count of parameters. \n"
			<< "Usage: findtext.exe <inputFile> <searchString> \n";
		return 1;
	}

	std::string fileName = argv[1];

	std::string searchString = argv[2];
	if (searchString.empty())
	{
		std::cout << "Search string must be not empty. \n";
		return 1;
	}

	result programResult = PrintLineNumbersContainingText(fileName, searchString);
	if (programResult == err)
	{
		std::cout << "Failed to open " << fileName << " for reading \n";
		return 1;
	}
	else if (programResult == text_not_found)
	{
		std::cout << "Text not found\n";
		return 1;
	}
	return 0;
}