#include "stdafx.h"
#include "DriveCar.h"
#include "Car.h"
#include <iterator>

using namespace std;
using namespace std::placeholders;

bool IsCorrectValue(int gear, int speed)
{
	if ((gear == -1 && speed >= 0 && speed <= 20) ||
		(gear == 0 && speed >= INT_MIN && speed <= INT_MAX) ||
		(gear == 1 && speed >= 0 && speed <= 30) ||
		(gear == 2 && speed >= 20 && speed <= 50) ||
		(gear == 3 && speed >= 30 && speed <= 60) ||
		(gear == 4 && speed >= 40 && speed <= 90) ||
		(gear == 5 && speed >= 50 && speed <= 150))
	{
		return true;
	}
	else
	{
		return false;
	}
}

CDriveCar::CDriveCar(std::istream & input, std::ostream & output)
	: m_input(input)
	, m_output(output)
	, m_actionMapInfo({
		{ "Info", [&]() { Info(); } },
		})
	, m_actionMapEngine({
		{ "EngineOn", [&]() { return OnEngine(); } },
		{ "EngineOff", [&]() { return OffEngine(); } },
		})
	, m_actionMapSpeedAndGear({
		{ "SetSpeed", [&](int number) { return SetSpeed(number); } },
		{ "SetGear", [&](int number) { return SetGear(number); } },
		})
{
}

static const std::map<CCar::Direction, std::string> MoveDirection = {
	{ CCar::Direction::Back, "Back" },
	{ CCar::Direction::Forward, "Forward" },
	{ CCar::Direction::Stop, "Stop" }
};

void CDriveCar::Info()
{
	m_output << "  Engine     :   " << (CCar::IsEngineTurnedOn() ? "On" : "Off") << "\n"
			 << "  Gear       :   " << (CCar::GetGear()) << "\n"
			 << "  Speed      :   " << (CCar::GetSpeed()) << "\n"
			 << "  Direction  :   " << (MoveDirection.at(CCar::GetDirection())) << "\n";
}

bool CDriveCar::OnEngine()
{
	if (CCar::IsEngineTurnedOn())
	{
		cout << "  Error: Engine turned on already" << endl;
	}
	CCar::TurnOnEngine();
	return true;
}

bool CDriveCar::OffEngine()
{
	if (!CCar::IsEngineTurnedOn())
	{
		cout << "  Error: Engine turned off already" << endl;
	}
	int gear = CCar::GetGear();
	int speed = CCar::GetSpeed();
	if ((gear != 0) || (speed != 0))
	{
		cout << "  Error: Speed and gear shoould be equal 0 for turn off engine" << endl;
	}
	CCar::TurnOffEngine();
	return true;
}

bool CDriveCar::SetGear(int gear)
{
	int speed = CCar::GetSpeed();
	int currentGear = CCar::GetGear();
	if (!IsEngineTurnedOn())
	{
		std::cout << "  Error: Engine should be turned on" << std::endl;
	} else if ((gear < -1) || (gear > 5)) {
		std::cout << "  Error: Use a gear value between -1 and 5" << std::endl;
	} else if ((gear == -1) && (speed != 0)) {
		std::cout << "  Error: Change to reverse gear can be done just when speed equals 0" << std::endl;
	} else if ((currentGear == -1) && (gear == 1) && (speed != 0)) {
		std::cout << "  Error: Change reverse gear to 1st can be done when speed equals 0" << std::endl;
	} else if (!IsCorrectValue(gear, speed)) {
		std::cout << " Error: Gear is not correct for this speed" << std::endl;
	}
	
	CCar::SetGear(gear);
	return true;
}

bool CDriveCar::SetSpeed(int speed)
{
	int gear = CCar::GetGear();
	int currentSpeed = CCar::GetSpeed();
	if (!IsEngineTurnedOn())
	{
		std::cout << "  Error: Engine should be turned on" << std::endl;
	} else if ((gear == 0) && (speed > currentSpeed) && (speed >= 0)) {
		std::cout << "  Error: Cannot set speed more than current if gear equals 0" << std::endl;
	} else if (speed < 0) {
		std::cout << "  Error: Speed cannot be negative" << std::endl;
	} else if (!IsCorrectValue(gear, speed)) {
		std::cout << " Error: Speed is not correct for this gear" << std::endl;
	}
	
	CCar::SetSpeed(speed);
	return true;
}

bool CDriveCar::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto itInfo = m_actionMapInfo.find(action);
	if (itInfo != m_actionMapInfo.end())
	{
		itInfo->second();
		return true;
	}

	auto itEngine = m_actionMapEngine.find(action);
	if (itEngine != m_actionMapEngine.end())
	{
		return itEngine->second();
		
	}

	auto itSpeedAndGear = m_actionMapSpeedAndGear.find(action);
	if (itSpeedAndGear != m_actionMapSpeedAndGear.end())
	{
		int number;
		if (GetValueSpeedOrGear(strm, number))
		{
			return itSpeedAndGear->second(number);
		}

	}
	return false;
}

bool CDriveCar::GetValueSpeedOrGear(std::istream & arg, int & number)
{
	std::string argString;
	arg >> argString;
	if (argString.empty())
	{
		std::cout << "  Error: Need to set a value" << std::endl;
	}
	try
	{
		number = stoi(argString);
	}
	catch (const std::exception& e)
	{
		std::cout << "  " << e.what() << std::endl;
	}
	return true;
}
