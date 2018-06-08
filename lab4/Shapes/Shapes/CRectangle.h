#pragma once
#include "ISolidShape.h"
#include "Point.h"

class CRectangle : public ISolidShape

{
public:
	CRectangle();
	CRectangle(CPoint const &leftTop, double width, double height, 
		std::string const &outlineColor, std::string const &fillColor);
	
	double GetArea() const override;
	double GetPerimeter() const override;

	std::string ToString() const override;
	std::string GetOutlineColor()const override;
	std::string GetFillColor() const override;
	double GetWidth() const;
	double GetHeight() const;

	CPoint GetLeftTop() const;
	//CPoint GetRightBottom() const;

private:
	double m_width;
	double m_height;

	CPoint m_leftTop;
	CPoint m_rightBottom;

	std::string m_outlineColor;
	std::string m_fillColor;
};

