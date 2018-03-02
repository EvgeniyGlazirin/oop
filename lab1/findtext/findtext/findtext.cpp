// findtext.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


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

	std::string line;
	bool found = false;

	for (int numberOfLine = 1; std::getline(inputFile, line); ++numberOfLine)
	{
		auto pos = line.find(searchString);
		if (pos != std::string::npos)
		{
			std::cout << numberOfLine << "\n";
			found = true;
		}
	}
	
	if (!found)
	{
		std::cout << "Text not found.\n";
	}

    return 0;
}

