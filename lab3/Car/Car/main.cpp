#include "stdafx.h"
#include "DriveCar.h"
#include "Car.h"

using namespace std;

int main()
{
	CCar car;
	CDriveCar driveCar(car, cin, cout);
	while (!cin.eof() && !cin.fail())
	{

		cout << "> ";
		if (!driveCar.HandleCommand())
		{
			cout << "  Unknown command!" << endl;
		}
	}

	return 0;
}