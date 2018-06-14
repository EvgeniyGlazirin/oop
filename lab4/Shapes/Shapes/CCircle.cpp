#include "stdafx.h"
#include "CCircle.h"

#define _USE_MATH_DEFINES
#include <math.h>

CCircle::CCircle(CPoint const & center, double const &radius, 
	std::string const &outlineColor, std::string const &fillColor)
	: m_center(center)
	, m_radius(radius)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

double CCircle::GetArea() const
{
	return ( M_PI * m_radius * m_radius);
}

double CCircle::GetPerimeter() const
{
	return (2 * M_PI * m_radius);
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

std::string CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CCircle::GetFillColor() const
{
	return m_fillColor;
}

std::string CCircle::ToString()const
{
	std::ostringstream strm;
	strm << "Circle:" << std::endl << std::setprecision(4) << std::fixed
		<< "area = " << GetArea() << std::endl
		<< "perimeter = " << GetPerimeter() << std::endl
		<< "outline color = " << GetOutlineColor() << std::endl
		<< "fill color = " << GetFillColor() << std::endl;
	return strm.str();
}