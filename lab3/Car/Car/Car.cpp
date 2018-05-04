// Car.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Car.h"

const std::vector <std::pair <int, int>> rangeSpeeds
{
	{ 0, 20 },
	{ INT_MIN, INT_MAX },
	{ 0, 30 },
	{ 20, 50 },
	{ 30, 60 },
	{ 40, 90 },
	{ 50, 150}
};

bool CCar::IsEngineTurnedOn() const
{
	return m_engineIsTurnedOn;
}

bool CCar::TurnOnEngine()
{
	if (!m_engineIsTurnedOn)
	{
		m_engineIsTurnedOn = true;
		return true;
	}
	return false;
}

bool CCar::TurnOffEngine()
{
	if (m_engineIsTurnedOn)
		// выключить
	{
		if (m_gear == 0 && m_speed == 0)
		{
			m_engineIsTurnedOn = false;
			return true;
		}
	}
	else
	{
		return false;
	}
}

int CCar::GetGear() const
{
	return m_gear;
}

bool CCar::SetGear(int gear)
{
	if (!m_engineIsTurnedOn && m_gear != 0)
	{
		return false;
	}
	else 

	return 0;
}
