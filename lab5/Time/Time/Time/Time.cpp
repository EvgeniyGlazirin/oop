// Time.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Time.h"
#include <stdexcept>

constexpr unsigned SECONDS_IN_A_MINUTE = 60;
constexpr unsigned SECONDS_IN_A_HOUR = 3600;
constexpr unsigned SECONDS_IN_A_DAY = 86400;
constexpr unsigned HOURS_IN_A_DAY = 24;
constexpr unsigned MINUTES_IN_A_HOUR = 60;


CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
{
	if ((hours >= HOURS_IN_A_DAY) || (minutes >= MINUTES_IN_A_HOUR) || (seconds >= SECONDS_IN_A_MINUTE))
	{
		throw std::invalid_argument
		("Invalid values. Try to enter values in ranges: hours(0-23), minutes(0-59), seconds(0-59)");
	}
	else
	{
		m_timeStamp = (hours * SECONDS_IN_A_HOUR) + (minutes * SECONDS_IN_A_MINUTE) + seconds;
	}
}


CTime::CTime(unsigned timeStamp)
{
	if (timeStamp >= SECONDS_IN_A_DAY)
	{
		throw std::invalid_argument("Invalid seconds value.");
	}
	m_timeStamp = timeStamp;
}

unsigned CTime::GetTimeStamp() const
{
	return m_timeStamp;
}

unsigned CTime::GetHours() const
{
	return m_timeStamp / SECONDS_IN_A_HOUR;
}

unsigned CTime::GetMinutes() const
{
	return (m_timeStamp / SECONDS_IN_A_MINUTE) % MINUTES_IN_A_HOUR;
}

unsigned CTime::GetSeconds() const
{
	return m_timeStamp % SECONDS_IN_A_MINUTE;
}

CTime & CTime::operator++()
{
	++m_timeStamp;
	if (m_timeStamp >= SECONDS_IN_A_DAY)
	{
		m_timeStamp = 0;
	}
	return *this;
}

CTime const CTime::operator++(int)
{
	CTime tempTime(*this);
	++*this;
	return tempTime;
}

CTime & CTime::operator--()
{
	if (m_timeStamp == 0)
	{
		m_timeStamp = SECONDS_IN_A_DAY - 1;
	}
	else
	{
		--m_timeStamp;
	}
	return *this;
}

CTime const CTime::operator--(int)
{
	CTime tempTime(*this);
	--*this;
	return tempTime;
}

CTime CTime::operator+(CTime const & time2) const
{
	unsigned resultOfSumTimes = m_timeStamp + time2.GetTimeStamp();
	return CTime(resultOfSumTimes % SECONDS_IN_A_DAY);
}

CTime CTime::operator-(CTime const & time2) const
{
	unsigned resultOfSubTimes = 0;
	if (m_timeStamp < time2.GetTimeStamp())
	{
		resultOfSubTimes = SECONDS_IN_A_DAY - (time2.GetTimeStamp() - m_timeStamp);
	}
	else
	{
		resultOfSubTimes = m_timeStamp - time2.GetTimeStamp();
	}
	return CTime(resultOfSubTimes);
}

CTime & CTime::operator+=(CTime const & sumTimeValue) 
{
	unsigned firstTime = m_timeStamp;
	unsigned timeStamp = (firstTime + sumTimeValue.m_timeStamp) % SECONDS_IN_A_DAY;
	m_timeStamp = timeStamp;
	return *this;
}

CTime & CTime::operator-=(CTime const & subTimeValue)
{
	unsigned firstTime = m_timeStamp;
	if (subTimeValue.m_timeStamp > firstTime)
	{
		m_timeStamp = SECONDS_IN_A_DAY - (subTimeValue.m_timeStamp - m_timeStamp);
		return *this;
	}
	else
	{
		m_timeStamp = firstTime - subTimeValue.m_timeStamp;
		return *this;
	}
}

CTime const CTime::operator*(unsigned number) const
{
	unsigned result = m_timeStamp * number;
	return CTime(result % SECONDS_IN_A_DAY);
}

CTime const CTime::operator/(unsigned number) const
{
	if (number <= 0)
	{
		throw std::invalid_argument("Invalid argument");
	}
	return CTime(m_timeStamp/number);
}

unsigned CTime::operator/(CTime const & time) const
{
	if (time.m_timeStamp == 0)
	{
		throw std::invalid_argument("Invalid argument");
	}
	return (m_timeStamp / time.m_timeStamp);
}

CTime & CTime::operator *= (unsigned number)
{
	m_timeStamp = m_timeStamp * number % SECONDS_IN_A_DAY;
	return *this;
}

CTime & CTime::operator /= (unsigned number)
{
	if (number <= 0)
	{
		throw std::invalid_argument("Invalid argument");
	}
	m_timeStamp = m_timeStamp / number;
	return *this;
}

bool CTime::operator==(CTime const & time) const
{
	return (m_timeStamp == time.m_timeStamp);
}

bool CTime::operator!=(CTime const & time) const
{
	return (m_timeStamp != time.m_timeStamp);
}

bool CTime::operator>(CTime const & time) const
{
	return (m_timeStamp > time.m_timeStamp);
}

bool CTime::operator<(CTime const & time) const
{
	return (m_timeStamp < time.m_timeStamp);
}

bool CTime::operator>=(CTime const & time) const
{
	return (m_timeStamp >= time.m_timeStamp);
}

bool CTime::operator<=(CTime const & time) const
{
	return (m_timeStamp <= time.m_timeStamp);
}