// flipbyte.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

uint8_t FlipByte(uint8_t inputByte)
{
	uint8_t outputByte;

	outputByte = ((inputByte & 0b11110000) >> 4) | ((inputByte & 0b00001111) << 4);
	outputByte = ((outputByte & 0b11001100) >> 2) | ((outputByte & 0b00110011) << 2);
	outputByte = ((outputByte & 0b10101010) >> 1) | ((outputByte & 0b01010101) << 1);

	return outputByte;
}

bool FitsToByte(int inputNumber)
{
	if ((inputNumber < 0) || (inputNumber > 255))
	{
		return false;
	}
	return true;
}

int main(int argc, char* argv[] )
{
	if (argc != 2)
	{
		std::cout << "Invalid count of arguments.\n" <<
			"Usage: flipbyte.exe <input byte> \n";
		return 1;
	}

	int number;
	try
	{
		number = std::stoi(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	if (!FitsToByte(number))
	{
		std::cout << "Invalid argument value. It must be beetwen 0 and 255. \n";
		return 1;
	}

	uint8_t byte = static_cast<uint8_t>(number);
	int outputNumber = FlipByte(byte);
	std::cout << outputNumber << "\n";
    return 0;
}

