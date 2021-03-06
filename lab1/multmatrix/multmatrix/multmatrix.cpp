// multmatrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

const int MATRIX_SIZE = 3;
using matrix = float[MATRIX_SIZE][MATRIX_SIZE];

void PrintMatrix(const matrix& matrix)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
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
	if (!matrixFile.is_open())
	{
		std::cout << "Failed to open " << fileName << " for reading \n";
		return false;
	}
	std::string line;
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		if (!std::getline(matrixFile, line))
		{
			return false;
		}
		std::istringstream row;
		row.str(line);
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			row >> matrix[i][j];
			if (row.fail())
				return false;
		}
	}
	return true;
}

void MultMatrix(const matrix matrix1, const matrix matrix2, matrix resultOfMultMatrix)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			resultOfMultMatrix[i][j] = 0;
			for (int k = 0; k < MATRIX_SIZE; k++)
				resultOfMultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid count of arguments.\n" <<
			"Usage: multmatrix.exe <firstMatrix file> <secondMatrix file> \n";
		return 1;
	}

	std::string firstMatrixFileName = argv[1];
	matrix matrix1;
	if (!ReadMatrixFromInputFile(matrix1, firstMatrixFileName))
	{
		return 1;
	}

	std::string secondMatrixFileName = argv[2];
	matrix matrix2;
	if (!ReadMatrixFromInputFile(matrix2, secondMatrixFileName))
	{
		return 1;
	}

	matrix resultOfMultMatrix;
	MultMatrix(matrix1, matrix2, resultOfMultMatrix);
	PrintMatrix(resultOfMultMatrix);
	return 0;
}

