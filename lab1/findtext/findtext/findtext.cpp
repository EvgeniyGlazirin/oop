// findtext.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

enum Result
{
	Text_Was_Found,
	Text_Not_Found,
	Err
};

Result PrintLineNumbersContainingText(const std::string &inputFileName, const std::string searchString)
{
	std::string line;
	std::ifstream file;
	file.open(inputFileName);
	if (!file.is_open())
	{
		return Err;
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
		return Text_Was_Found;
	} 
	else
	{
		return Text_Not_Found;
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

	Result programResult = PrintLineNumbersContainingText(fileName, searchString);
	if (programResult == Err)
	{
		std::cout << "Failed to open " << fileName << " for reading \n";
		return 1;
	} else if (programResult == Text_Not_Found) {
		std::cout << "Text not found\n";
		return 1;
	}
	return 0;
}