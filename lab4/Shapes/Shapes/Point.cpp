#include "stdafx.h"
#include "Point.h"

CPoint::CPoint()
{
}

CPoint::CPoint(double x, double y)
	: m_x(x)
	, m_y(y)
{
}

double CPoint::GetX() const
{
	return m_x;
}

double CPoint::GetY() const
{
	return m_y;
}

void CPoint::SetCoordinates(const double x, const double y)
{
	m_x = x;
	m_y = y;
}

double CPoint::GetLenghtToPoint(CPoint const & point) const
{
	return sqrt(pow((m_x - point.GetX()), 2)
		+ pow((m_y - point.GetY()), 2));
}
