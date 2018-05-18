#pragma once
#include "Car.h"

class CDriveCar : public CCar
{
public:
	CDriveCar(std::istream & input, std::ostream & output);
	bool HandleCommand();
private:
	void Info();
	bool OnEngine();
	bool OffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	bool GetValueSpeedOrGear(std::istream & arg, int& number);
private:
	std::istream & m_input;
	std::ostream & m_output;

	const std::map<std::string, std::function<void()>> m_actionMapInfo;
	const std::map<std::string, std::function<bool()>> m_actionMapEngine;
	const std::map<std::string, std::function<bool(int number)
		>> m_actionMapSpeedAndGear;
};

