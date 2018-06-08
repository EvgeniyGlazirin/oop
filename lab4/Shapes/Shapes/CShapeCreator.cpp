#include "stdafx.h"
#include "CShapeCreator.h"
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"


CShapeCreator::CShapeCreator(std::istream& input)
	: m_actionMap({
		{ "line", bind(&CShapeCreator::CreateLine, this, std::placeholders::_1) },
		{ "circle", bind(&CShapeCreator::CreateCircle, this, std::placeholders::_1) },
		{ "rectangle", bind(&CShapeCreator::CreateRectangle, this, std::placeholders::_1) },
		{ "triangle", bind(&CShapeCreator::CreateTriangle, this, std::placeholders::_1) } })
		, m_input(input)
{
}

CShapeCreator::~CShapeCreator()
{
}

std::shared_ptr<IShape> CShapeCreator::HandleCommand() const
{
	std::string command;
	std::getline(m_input, command);
	std::istringstream strm(command);
	std::string figure;
	strm >> figure;

	auto it = m_actionMap.find(figure);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}
	throw std::exception("Unknown command");
}

std::shared_ptr<IShape> CShapeCreator::CreateLine(std::istringstream & strm) const
{
	CPoint startPoint, endPoint;
	std::string outlineColor, input, input2;

	try
	{
		strm >> input >> input2;
		startPoint.SetCoordinates(std::stod(input), std::stod(input2));
		input.clear();
		input2.clear();

		strm >> input >> input2;
		endPoint.SetCoordinates(std::stod(input), std::stod(input2));

		strm >> outlineColor;
	}

	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}

	return std::make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
}

std::shared_ptr<IShape> CShapeCreator::CreateTriangle(std::istringstream & strm) const
{
	CPoint vertex1, vertex2, vertex3;
	std::string fillColor, outlineColor, input, input2;

	try
	{
		strm >> input >> input2;
		vertex1.SetCoordinates(std::stod(input), std::stod(input2));
		input.clear();
		input2.clear();

		strm >> input >> input2;
		vertex2.SetCoordinates(std::stod(input), std::stod(input2));
		input.clear();
		input2.clear();

		strm >> input >> input2;
		vertex3.SetCoordinates(stod(input), stod(input2));
		input.clear();
		input2.clear();

		strm >> outlineColor;

		strm >> fillColor;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}
	return std::make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
}

std::shared_ptr<IShape> CShapeCreator::CreateRectangle(std::istringstream & strm) const
{
	CPoint leftTop;
	double width, height;
	std::string fillColor, outlineColor, input, input2;

	try
	{
		strm >> input >> input2;
		leftTop.SetCoordinates(std::stod(input), std::stod(input2));
		input.clear();
		input2.clear();

		strm >> input;
		width = std::stod(input);
		input.clear();

		strm >> input;
		height = std::stod(input);
		input.clear();

		strm >> outlineColor;
		strm >> fillColor;

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}

	return std::make_shared<CRectangle>(leftTop, width, height, outlineColor, fillColor);
}

std::shared_ptr<IShape> CShapeCreator::CreateCircle(std::istringstream & strm) const
{
	CPoint center;
	double radius;
	std::string fillColor, outlineColor, input, input2;
	
	try
	{
		strm >> input >> input2;
		center.SetCoordinates(std::stod(input), std::stod(input2));
		input.clear();
		input2.clear();

		strm >> input;
		radius = std::stod(input);
		input.clear();

		strm >> outlineColor;
		strm >> fillColor;

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}

	return std::make_shared<CCircle>(center, radius, outlineColor, fillColor);
}