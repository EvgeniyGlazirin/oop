// multmatrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main(int argc, char* argv[] )
{


	if (argc != 3)
	{
		std::cout << "Invalid count of arguments.\n" <<
			"Usage: multmatrix.exe <firstMatrix file> <secondMatrix file> \n";
		return 1;
	}

	std::ifstream firstMatrix(argv[1]);
	std::ifstream secondMatrix(argv[2]);
	firstMatrix.open(argv[1]);
		if (!firstMatrix.is_open())
	{
		std::cout << "Failed to open " << argv[1] << " for reading \n";
		return 1;
	}

	secondMatrix.open(argv[2]);
	if (!secondMatrix.is_open())
	{
		std::cout << "Failed to open " << argv[2] << " for reading \n";
		return 1;
	}



    return 0;
}

