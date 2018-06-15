#pragma once
#include "stdafx.h"
#include "IShape.h"


class CShapeCreator
{
public:
	CShapeCreator(std::istream &input);
	~CShapeCreator();
	std::shared_ptr<IShape> Command() const;

private:
	std::map<std::string, std::function<std::shared_ptr<IShape>(std::istringstream &strm)>> m_actionMap;
	std::shared_ptr<IShape> CreateLine(std::istringstream & strm) const;
	std::shared_ptr<IShape> CreateTriangle(std::istringstream & strm) const;
	std::shared_ptr<IShape> CreateRectangle(std::istringstream & strm) const;
	std::shared_ptr<IShape> CreateCircle(std::istringstream & strm) const;
	std::istream& m_input;
};

