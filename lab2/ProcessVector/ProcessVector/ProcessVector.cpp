// MultOnMinElement.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ProcessVector.h"


void ReadVector(std::istream &input, std::vector<double> &vec)
{
	std::copy(std::istream_iterator<double>(input), std::istream_iterator<double>(), std::back_inserter(vec));
}

void ProcessVector(std::vector<double> &vec)
{
	if (vec.empty())
	{
		return;
	}

    const double minElementOfVector = *std::min_element(vec.begin(), vec.end());
	std::transform(vec.begin(), vec.end(), vec.begin(), [=](double number) { return number = number * minElementOfVector; });
	
	return;
}

void PrintVector(std::ostream  &output, std::vector<double> &vec)
{
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<double>(output, " "));
}