#pragma once
#include "Car.h"

class CDriveCar
{
public:
	CDriveCar(CCar &car, std::istream & input, std::ostream & output);
	bool HandleCommand();
private:
	bool Info(std::istream & args);
	bool OnEngine(std::istream & args);
	bool OffEngine(std::istream & args);
	bool SetGear(std::istream & args);
	bool SetSpeed(std::istream & args);
private:
	std::istream & m_input;
	std::ostream & m_output;
	CCar &m_car;

	typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;
	const ActionMap m_actionMap;
};

