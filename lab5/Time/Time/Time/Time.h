#pragma once
// ���������� ����� �����, ���������� ����������� ����� (0-23), ����� (0-59) � // ������ (0-59)
class CTime
{
public:

	// �������������� ����� �������� ����������� �����, ����� � ������
	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);

	// �������������� ����� ����������� ������ ����� ��������
	explicit CTime(unsigned timeStamp = 0);
	
	unsigned GetTimeStamp() const;

	// ���������� ���������� �����
	unsigned GetHours()const;
	
	// ���������� ���������� �����
	unsigned GetMinutes()const;
	
	// ���������� ���������� ������
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

