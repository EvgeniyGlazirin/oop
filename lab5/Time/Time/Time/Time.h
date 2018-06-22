#pragma once
// моделирует время суток, задаваемое количеством часов (0-23), минут (0-59) и // секунд (0-59)
class CTime
{
public:

	// инициализирует время заданным количеством часов, минут и секунд
	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);

	// инициализирует время количеством секунд после полуночи
	explicit CTime(unsigned timeStamp = 0);
	
	unsigned GetTimeStamp() const;

	// возвращает количество часов
	unsigned GetHours()const;
	
	// возвращает количество минут
	unsigned GetMinutes()const;
	
	// возвращает количество секунд
	unsigned GetSeconds()const;

	CTime & operator++();

	CTime const operator++(int);

	CTime & operator--();

	CTime const operator--(int);

	CTime operator+(CTime const & time2) const;

	CTime operator-(CTime const & time2) const;

	CTime & operator+=(CTime const & time2);

	CTime & operator-=(CTime const & time2);

	CTime const operator*(unsigned number) const;

	unsigned operator*(CTime const & time) const;

	CTime const operator/(unsigned number)const;

	unsigned operator/(CTime const& time) const;

	CTime & operator *= (unsigned number);

	CTime & operator /= (unsigned number);

	bool operator == (CTime const& time) const;

	bool operator != (CTime const& time) const;

	bool operator > (CTime const& time) const;

	bool operator < (CTime const& time) const;

	bool operator >= (CTime const& time) const;

	bool operator <= (CTime const& time) const;

private:
	unsigned m_timeStamp = 0;
};

