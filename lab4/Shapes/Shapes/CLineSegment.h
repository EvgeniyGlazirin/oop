#pragma once
#include "Ishape.h"
#include "Point.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(CPoint const & startPoint, CPoint const & endPoint,
		std::string const &outlineColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;

	std::string m_outlineColor;
};

