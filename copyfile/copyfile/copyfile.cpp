// copyfile.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void CopyFile(std::istream& input, std::ostream& output)
{
	std::string str;
	while (!input.eof())
	{
		std::getline(input, str);
		output << str;
	}

}
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid arguments count\n"
			<< "Usage: copyfile.exe <inputFile> <outputFile>\n";
		return 1;
	}

	std::ifstream inputFile;
	inputFile.open(argv[1]);
	if (!inputFile.is_open())
	{
		std::cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	std::ofstream outputFile;
	outputFile.open(argv[2]);
	if (!outputFile.is_open())
	{
		std::cout << "Failed to open " << argv[2] << " for writing\n";
		return 1;
	}

	CopyFile(inputFile, outputFile);
	outputFile.flush();

    return 0;
}

