#include "stdafx.h"
#include "CRectangle.h"
#include <iostream>

using namespace std;

CRectangle::CRectangle()
{
}

CRectangle::CRectangle(CPoint const &leftTop, double width, double height, 
	std::string const &outlineColor, std::string const &fillColor)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return ((m_width * 2) + (m_height * 2));
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

std::string CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CRectangle::GetFillColor() const
{
	return m_fillColor;
}

std::string CRectangle::ToString()const
{
	std::ostringstream strm;
	strm << "Rectangle:" << std::endl << std::setprecision(4) << std::fixed
		<< "area = " << GetArea() << std::endl
		<< "perimeter = " << GetPerimeter() << std::endl
		<< "outline color = " << GetOutlineColor() << std::endl
		<< "fill color = " << GetFillColor() << std::endl;
	return strm.str();
}