#include "stdafx.h"
#include "CTriangle.h"


CTriangle::CTriangle()
{
}

CTriangle::CTriangle(CPoint const & point1, CPoint const & point2, CPoint const & point3,
	std::string const &outlineColor, std::string const &fillColor)
	: m_vertex1(point1)
	, m_vertex2(point2)
	, m_vertex3(point3)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

double CTriangle::GetPerimeter() const
{
	return (GetLength(m_vertex1, m_vertex2) + GetLength(m_vertex2, m_vertex3)
		+ GetLength(m_vertex3, m_vertex1));
}

double CTriangle::GetArea() const
{
	double halfPerimeter = CTriangle::GetPerimeter() / 2;
	return sqrt(halfPerimeter * (halfPerimeter - GetLength(m_vertex1, m_vertex2)) 
		* (halfPerimeter - GetLength(m_vertex2, m_vertex3))
		* (halfPerimeter - GetLength(m_vertex3, m_vertex1)));
}

std::string CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CTriangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

double CTriangle::GetLength(CPoint const & point1, CPoint const & point2) const
{
	return sqrt(pow((point1.GetX() - point2.GetX()), 2)
		+ pow((point1.GetY() - point2.GetY()), 2));
}

std::string CTriangle::ToString()const
{
	std::ostringstream strm;
	strm << "Triangle:" << std::endl << std::setprecision(4) << std::fixed
		<< "area = " << GetArea() << std::endl
		<< "perimeter = " << GetPerimeter() << std::endl
		<< "outline color = " << GetOutlineColor() << std::endl
		<< "fill color = " << GetFillColor() << std::endl;
	return strm.str();
}