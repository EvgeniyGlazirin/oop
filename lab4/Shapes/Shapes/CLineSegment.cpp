#include "stdafx.h"
#include "CLineSegment.h"

CLineSegment::CLineSegment(CPoint const & startPoint, CPoint const & endPoint,
	std::string const &outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, m_outlineColor(outlineColor)
{
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return sqrt(pow((m_endPoint.GetX() - m_startPoint.GetX()), 2)
		+ pow((m_endPoint.GetY() - m_startPoint.GetY()), 2));
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

std::string CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CLineSegment::ToString()const
{
	std::ostringstream strm;
	strm << "Line segment:" << std::endl << std::setprecision(4) << std::fixed
		<< "area = " << GetArea() << std::endl
		<< "perimeter = " << GetPerimeter() << std::endl
		<< "outline color = " << GetOutlineColor() << std::endl;
	return strm.str();
}
