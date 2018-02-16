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

	std::ofstream outputFile;
	outputFile.open(argv[2]);

	CopyFile(inputFile, outputFile);
	outputFile.flush();

    return 0;
}

