#include "stdafx.h"
#include "IShape.h"
#include "CShapeCreator.h"

bool CompareShapeAreas(const std::shared_ptr<IShape> &shape, const std::shared_ptr<IShape> &nextShape)
{
	return (shape->GetArea() < nextShape->GetArea());
}

std::string GetMaxShapeArea(const std::vector<std::shared_ptr<IShape>> & shapes)
{
	auto maxAreaShape = std::max_element(shapes.begin(), shapes.end(), CompareShapeAreas);
	return (*maxAreaShape)->ToString();
}

bool CompareShapePerimeters(const std::shared_ptr<IShape> &shape, const std::shared_ptr<IShape> &nextShape)
{
	return (shape->GetArea() < nextShape->GetArea());
}

std::string GetMinShapePerimeter(const std::vector<std::shared_ptr<IShape>> & shapes)
{
	auto minPerimeterShape = std::min_element(shapes.begin(), shapes.end(), CompareShapePerimeters);
	return (*minPerimeterShape)->ToString();
}


void PrintInformation()
{
	std::string information = "Enter firures according the form: \n"
	"Line: line <start point> <end point> <line color>\n"
	"Rectangle: rectangle <left top> <width> <height> <outline color>  <fill color> \n"
	"Triangle: triangle <vertex1> <vertex2> <vertex3> <outline color> <fill color> \n"
	"Circle: circle <center> <radius> <outline color> <fill color>\n"
	"Every point consist of coordinates: <x> <y>\n \n"
	"Example: rectangle 10.3 20.15 30.7 40.4 ff0000 00ff00 \n";

	std::cout << information << std::endl;
}

int main()
{
	PrintInformation();

	std::vector<std::shared_ptr<IShape>> shapes;
	CShapeCreator ShapeCreator(std::cin);

	while (auto shape = ShapeCreator.Command())
	{
		shapes.push_back(shape);
	}

	if (!shapes.empty())
	{
		std::cout << "Shape with max area: " << std::endl;
		std::cout << GetMaxShapeArea(shapes) << std::endl;

		std::cout << "Shape with min perimeter: " << std::endl;
		std::cout << GetMinShapePerimeter(shapes) << std::endl;
	}
	else
	{
		std::cout << "No any shapes" << std::endl;
	}
	return 0;
}