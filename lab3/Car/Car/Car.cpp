// Car.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Car.h"


bool IsSpeedCorrectForGear(int gear, int speed)
{
	if ((gear == -1 && speed <= 0 && speed >= -20) ||
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
	{
		if (m_gear == 0 && m_speed == 0)
		{
			m_engineIsTurnedOn = false;
			return true;
		}
		else
		{
			return false;
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
	if (!CCar::IsEngineTurnedOn())
	{
		return false;
	}
	else if ((gear < -1) || (gear > 5))
	{
		return false;
	}
	else if (gear == 0)
	{
		m_gear = gear;
		return true;
	}
	else if ((gear == -1) && (CCar::GetSpeed() != 0))
	{
		return false;
	}
	else if ((gear == 1) && (m_speed != 0) || ((gear > 0) && CCar::GetDirection() == Direction::Back))
	{
		return false;
	}
	else if (!IsSpeedCorrectForGear(gear, m_speed))
	{
		return false;
	}
	else 
	{
		m_gear = gear;
		return true;
	}
}

int CCar::GetSpeed() const
{
	return std::abs(m_speed);
}

bool CCar::SetSpeed(int speed)
{
	if (!m_engineIsTurnedOn)
	{
		return false;
	}
	else if (speed < 0)
	{
		return false;
	}
	else if ((m_gear == 0) && (std::abs(speed) > std::abs(m_speed)))
	{
		return false;
	}
	else if (m_gear == -1)
	{
		if (IsSpeedCorrectForGear(m_gear, -speed))
		{
			m_speed = -speed;
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (IsSpeedCorrectForGear(m_gear, speed))
	{
		if (m_gear == -1 || m_speed < 0)
		{
			speed = -speed;
		}
		m_speed = speed;
		return true;
	}
	else
	{
		return false;
	}

}
CCar::Direction CCar::GetDirection() const
{
	if (m_speed < 0)
	{
		return Direction::Back;
	}
	else if (m_speed == 0)
	{
		return Direction::Stop;
	}
	else
	{
		return Direction::Forward;
	}
}