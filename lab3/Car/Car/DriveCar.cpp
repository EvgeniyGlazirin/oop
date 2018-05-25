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

CDriveCar::CDriveCar(CCar &car, std::istream & input, std::ostream & output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "Info", std::bind(&CDriveCar::Info, this, std::placeholders::_1) },
		{ "EngineOn", std::bind(&CDriveCar::OnEngine, this, std::placeholders::_1) },
		{ "EngineOff", std::bind(&CDriveCar::OffEngine, this, std::placeholders::_1) },
		{ "SetGear", std::bind(&CDriveCar::SetGear, this, std::placeholders::_1) },
		{ "SetSpeed", std::bind(&CDriveCar::SetSpeed, this, std::placeholders::_1) }
		})
{
}

bool CDriveCar::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}
	return false;
}

static const std::map<CCar::Direction, std::string> MoveDirection = {
	{ CCar::Direction::Back, "Back" },
	{ CCar::Direction::Forward, "Forward" },
	{ CCar::Direction::Stop, "Stop" }
};

bool CDriveCar::Info(std::istream &)
{
	m_output << "  Engine     :   " << (m_car.IsEngineTurnedOn() ? "On" : "Off") << "\n"
			 << "  Gear       :   " << (m_car.GetGear()) << "\n"
			 << "  Speed      :   " << (m_car.GetSpeed()) << "\n"
			 << "  Direction  :   " << (MoveDirection.at(m_car.GetDirection())) << "\n";
	return true;
}

bool IsConvertStringToInteger(const string & args, int & number)
{
	try
	{
		number = stoi(args);
	}
	catch (const std::exception& e)
	{
		std::cout << "  " << e.what() << std::endl;
	}
	return true;
}

bool CDriveCar::OnEngine(std::istream &)
{
	if (m_car.IsEngineTurnedOn())
	{
		cout << "  Error: Engine turned on already" << endl;
	}
	m_car.TurnOnEngine();
	return true;
}

bool CDriveCar::OffEngine(std::istream &)
{
	if (!m_car.IsEngineTurnedOn())
	{
		cout << "  Error: Engine turned off already" << endl;
	}
	int gear = m_car.GetGear();
	int speed = m_car.GetSpeed();
	if ((gear != 0) || (speed != 0))
	{
		cout << "  Error: Speed and gear shoould be equal 0 for turn off engine" << endl;
	}
	m_car.TurnOffEngine();
	return true;
}

bool CDriveCar::SetGear(std::istream & args)
{
	int gear;
	string input;
	args >> input;

	int speed = m_car.GetSpeed();
	int currentGear = m_car.GetGear();

	if (IsConvertStringToInteger(input, gear))
	{
		if (!m_car.IsEngineTurnedOn())
		{
			std::cout << "  Error: Engine should be turned on" << std::endl;
		}
		else if ((gear < -1) || (gear > 5))
		{
			std::cout << "  Error: Use a gear value between -1 and 5" << std::endl;
		}
		else if ((gear == -1) && (speed != 0))
		{
			std::cout << "  Error: Change to reverse gear can be done just when speed equals 0" << std::endl;
		}
		else if ((currentGear == -1) && (gear == 1) && (speed != 0))
		{
			std::cout << "  Error: Change reverse gear to 1st can be done when speed equals 0" << std::endl;
		}
		else if (!IsCorrectValue(gear, speed))
		{
			std::cout << "  Error: Gear is not correct for this speed" << std::endl;
		}
	}
	else
	{
		std::cout << "  Error: Invalid speed value" << std::endl;
	}

	m_car.SetGear(gear);
	return true;
}

bool CDriveCar::SetSpeed(std::istream & args)
{
	int speed;
	string input;
	args >> input;

	int gear = m_car.GetGear();
	int currentSpeed = m_car.GetSpeed();
	if (IsConvertStringToInteger(input, speed))
	{
		if (!m_car.IsEngineTurnedOn())
		{
			std::cout << "  Error: Engine should be turned on" << std::endl;
		}
		else if ((gear == 0) && (speed > currentSpeed) && (speed >= 0))
		{
			std::cout << "  Error: Cannot set speed more than current if gear equals 0" << std::endl;
		}
		else if (speed < 0)
		{
			std::cout << "  Error: Speed cannot be negative" << std::endl;
		}
		else if (!IsCorrectValue(gear, speed))
		{
			std::cout << "  Error: Speed is not correct for this gear" << std::endl;
		}
	}
	else
	{
		std::cout << "  Error: Invalid gear value" << std::endl;
	}
	m_car.SetSpeed(speed);
	return true;
}
