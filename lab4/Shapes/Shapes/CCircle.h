#pragma once
#include "ISolidShape.h"
#include "Point.h"

class CCircle : public ISolidShape
{
public:
	CCircle(CPoint const & center, double const &radius, 
		std::string const &outlineColor, std::string const &fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor()const override;
	std::string GetFillColor() const override;
	CPoint GetCenter() const;
	double GetRadius() const;
private:
	double m_radius;
	CPoint m_center;

	std::string m_outlineColor;
	std::string m_fillColor;
};

