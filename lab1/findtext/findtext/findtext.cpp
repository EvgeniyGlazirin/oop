// findtext.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


bool CheckFileToOpenForReading(const std::string &inputFile)
{
	std::ifstream file ;
	file.open(inputFile);
	if (!file.is_open())
	{
		std::cout << "Failed to open " << inputFile << " for reading \n";
		return false;
	}
	return true;
}

bool IsSearchStringEmpty(std::string searchString)
{
	if (searchString.empty())
	{
		std::cout << "Search string must be not empty. \n";
		return false;
	}
	return true;
}



bool PrintLineNumbersContainingText(const std::string &inputFile, std::string searchString)
{
	std::string line;
	bool stringWasFound = false;
	std::ifstream file;
	file.open(inputFile);

	for (int numberOfLine = 1; std::getline(file, line); ++numberOfLine)
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

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid count of parameters. \n"
			<< "Usage: findtext.exe <inputFile> <searchString> \n";
		return 1;
	}

	std::string fileName = argv[1];
	if(!CheckFileToOpenForReading(fileName))
	{
		return 1;
	}

	std::string searchString = argv[2];
	if (!IsSearchStringEmpty(searchString))
	{
		return 1;
	}


	if (PrintLineNumbersContainingText(fileName, searchString))
	{
		return 0;
	}
	else
	{
		std::cout << "Text not found.\n";
		return 1;
	}


}

