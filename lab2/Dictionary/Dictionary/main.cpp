#include "stdafx.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	std::string dictionaryName;

	if (argc > 2)
	{
		std::cout << "Invalid count of arguments" << std::endl;
		return 1;
	}
	else if(argc == 2)
	{
		std::string dictionaryName = argv[1];
		std::ifstream dictionaryFile;
		dictionaryFile.open(dictionaryName);
		if (!dictionaryFile.is_open())
		{
			std::cout << "Failed to open " << dictionaryName << std::endl;
			return 1;
		}
	}
	else
	{
		//create new temporary dictionary
		// dictionaryName = "temporaryDictionary";
	}
	//WorkWithTheDictionary();
	/*

	std::string userInput;
	//std::string exitFromTheProgram;
	std::cout << "¬ведите слово" << std::endl;
	
	while (std::getline(std::cin, userInput))
	{
		while (userInput != "...")
		{
			std::cout << "name is " << userInput << std::endl;
			break;
			
			if (WordTranslationIsInDictionary(userInput))
			{
				// function PrintTheTranslation
			}
			else
			{
				// function AddNewWord
			}
		}

		break;
		/*while (userInput != "...")
		{
			std::cout << "name is " << userInput << std::endl;
			break;
		}

	}
	
	//std::cout << "name is" << dictionaryName << std::endl;
	if (WordTranslationIsInDictionary(userInput))
	{
		// function PrintTheTranslation
	}
	else
	{
		// function AddNewWord
	}
	
	*/
	return 0;
}