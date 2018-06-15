#pragma once
#include "ISolidShape.h"
#include "Point.h"

class CTriangle : public virtual ISolidShape
{
public:
	CTriangle(CPoint const & point1, CPoint const & point2, CPoint const & point3, 
		std::string const &outlineColor, std::string const &fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor()const override;
	std::string GetFillColor() const override;
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;
private:

	std::string m_outlineColor;
	std::string m_fillColor;
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};

