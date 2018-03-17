// multmatrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


const int matrixSize = 3;
using matrix = float[matrixSize][matrixSize];


void PrintMatrix(const matrix& matrix)
{
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}

bool ReadMatrixFromInputFile(matrix& matrix, const std::string & fileName)
{
	std::ifstream matrixFile;
	matrixFile.open(fileName);
	std::string line;
	if (!matrixFile.is_open())
	{
		return false;
	}
	for (int i = 0; i < matrixSize; i++)
	{
		if (!std::getline(matrixFile, line))
		{
			return false;
		}
		std::istringstream row;
		row.str(line);
		for (int j = 0; j < 3; j++)
		{
			row >> matrix[i][j];
			if (row.fail())
				return false;
		}
	}

	return true;
}


int main(int argc, char* argv[])
{


	if (argc != 3)
	{
		std::cout << "Invalid count of arguments.\n" <<
			"Usage: multmatrix.exe <firstMatrix file> <secondMatrix file> \n";
		return 1;
	}

	std::ifstream firstMatrix(argv[1]);
	firstMatrix.open(argv[1]);
	if (!firstMatrix.is_open())
	{
		std::cout << "Failed to open " << argv[1] << " for reading \n";
		return 1;
	}
 
	matrix matrix1;
	std::string fileName = argv[1];
	ReadMatrixFromInputFile(matrix1, fileName);
	//PrintMatrix(matrix1);

	std::ifstream secondMatrix(argv[2]);
	secondMatrix.open(argv[2]);
	if (!secondMatrix.is_open())
	{
		std::cout << "Failed to open " << argv[2] << " for reading \n";
		return 1;
	}

	matrix matrix2;
	std::string fileName2 = argv[2];
	ReadMatrixFromInputFile(matrix2, fileName2);
	//PrintMatrix(matrix2);



    return 0;
}

