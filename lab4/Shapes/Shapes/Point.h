#pragma once
class CPoint
{
public:
	CPoint(const double x, const double y);
	CPoint();
	double GetX() const;
	double GetY() const;
	void SetCoordinates(const double x, const double y);

private:
	double m_x;
	double m_y;
};

