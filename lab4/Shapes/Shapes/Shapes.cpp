#include "stdafx.h"
#include "IShape.h"
#include "CShapeCreator.h"


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

	while (auto shape = ShapeCreator.HandleCommand())
		{
			shapes.push_back(shape);
		}

	if (!shapes.empty())
		{
			std::cout << "Shape with max area: " << std::endl;
		//	std::cout << GetMaxShapeArea(shapes) << std::endl;

			std::cout << "Shape with min perimeter: " << std::endl;
			//std::cout << GetMinShapePerimeter(shapes) << std::endl;
		}

	return 0;
}