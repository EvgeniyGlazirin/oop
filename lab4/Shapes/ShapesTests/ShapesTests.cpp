// ShapesTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Shapes/Point.h"
#include "../Shapes/ISolidShape.h"
#include "../Shapes/CCircle.h"
#include "../Shapes/CTriangle.h"
#include "../Shapes/CRectangle.h"
#include "../Shapes/IShape.h"
#include "../Shapes/CLineSegment.h"
#include "../Shapes/CShapeCreator.h"

bool PointsAreEquals(const CPoint & first, const CPoint & second)
{
	if ((first.GetX() == second.GetX()) && (first.GetY() == second.GetY()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void VerifyHandleCommand(const std::string &command, const std::string &expectedOutput)
{
	std::stringstream input;
	input = std::stringstream();
	CShapeCreator shapeCreator(input);
	std::shared_ptr<IShape> shape;

	BOOST_CHECK(input << command);
	shape = shapeCreator.Command();
	BOOST_CHECK(shape->ToString() == expectedOutput);
}

BOOST_AUTO_TEST_SUITE(Point)
BOOST_AUTO_TEST_CASE(has_cordinates)
{
	CPoint point(1, 2.1);
	BOOST_CHECK_EQUAL(point.GetX(), 1);
	BOOST_CHECK_EQUAL(point.GetY(), 2.1);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(LineSegment)
BOOST_AUTO_TEST_CASE(get_area_perimeter_and_color)
{
	CPoint startPoint(1, 1);
	CPoint endPoint(1, 6);
	std::string color = "fff000";
	CLineSegment line(startPoint, endPoint, color);
	BOOST_CHECK(PointsAreEquals(line.GetStartPoint(), startPoint));
	BOOST_CHECK(PointsAreEquals(line.GetEndPoint(), endPoint));
	BOOST_CHECK_EQUAL(line.GetArea(), 0);
	BOOST_CHECK_EQUAL(line.GetPerimeter(), 5);
	BOOST_CHECK_EQUAL(line.GetOutlineColor(), "fff000");
}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(Circle)
CPoint center(0, 0);
double radius = 5;
std::string fillColor = "fff000";
std::string outlineColor = "000fff";
CCircle circle(center, radius, outlineColor, fillColor);

BOOST_AUTO_TEST_CASE(can_be_created_with_valid_parameters)
{
	BOOST_CHECK(PointsAreEquals(circle.GetCenter(), center));
	BOOST_CHECK_EQUAL(circle.GetRadius(), radius);
	BOOST_CHECK_EQUAL(circle.GetFillColor(), fillColor);
	BOOST_CHECK_EQUAL(circle.GetOutlineColor(), outlineColor);
}

BOOST_AUTO_TEST_CASE(get_area_perimeter_outline_and_fill_colors)
{
	double area = M_PI * radius * radius;
	BOOST_CHECK_EQUAL(circle.GetArea(), area);

	double perimeter = M_PI * radius * 2;
	BOOST_CHECK_EQUAL(circle.GetPerimeter(), perimeter);

	BOOST_CHECK_EQUAL(circle.GetOutlineColor(), "000fff");
	BOOST_CHECK_EQUAL(circle.GetFillColor(), "fff000");
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Triangle)
CPoint v1(0, 0);
CPoint v2(2, 0);
CPoint v3(0, 2);
std::string fillColor = "fff000";
std::string outlineColor = "000fff";
CTriangle triangle(v1, v2, v3, outlineColor, fillColor);

BOOST_AUTO_TEST_CASE(can_be_created_with_valid_parameters)
{
	BOOST_CHECK(PointsAreEquals(triangle.GetVertex1(), v1));
	BOOST_CHECK(PointsAreEquals(triangle.GetVertex2(), v2));
	BOOST_CHECK(PointsAreEquals(triangle.GetVertex3(), v3));
	BOOST_CHECK_EQUAL(triangle.GetFillColor(), fillColor);
	BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), outlineColor);

}

BOOST_AUTO_TEST_CASE(get_area_perimeter_outline_and_fill_colors)
{
	double halfPerimeter = 0.5 * triangle.GetPerimeter();
	double firstEfficient = halfPerimeter - sqrt(pow((v1.GetX() - v2.GetX()), 2)
		+ pow((v1.GetY() - v2.GetY()), 2));
	double secondEfficient = halfPerimeter - sqrt(pow((v2.GetX() - v3.GetX()), 2)
		+ pow((v2.GetY() - v3.GetY()), 2));
	double thirdEfficient = halfPerimeter - sqrt(pow((v3.GetX() - v1.GetX()), 2)
		+ pow((v3.GetY() - v1.GetY()), 2));

	double area = sqrt(halfPerimeter * firstEfficient * secondEfficient * thirdEfficient);
	BOOST_CHECK_EQUAL(triangle.GetArea(), area);

	BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), "000fff");
	BOOST_CHECK_EQUAL(triangle.GetFillColor(), "fff000");


}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Rectangle)

CPoint leftTop(1, 1);
double width = 10;
double height = 20;
std::string fillColor = "ff0000";
std::string outlineColor = "000fff";
CRectangle rectangle(leftTop, width, height, outlineColor, fillColor);

BOOST_AUTO_TEST_CASE(can_be_created_with_valid_parameters)
{
	BOOST_CHECK(PointsAreEquals(rectangle.GetLeftTop(), leftTop));
	BOOST_CHECK_EQUAL(rectangle.GetWidth(), 10);
	BOOST_CHECK_EQUAL(rectangle.GetHeight(), 20);
	BOOST_CHECK_EQUAL(rectangle.GetOutlineColor(), outlineColor);
	BOOST_CHECK_EQUAL(rectangle.GetFillColor(), fillColor);
}

BOOST_AUTO_TEST_CASE(get_area_and_perimeter_outline_and_fill_colors)
{

	double area = width * height;
	BOOST_CHECK_EQUAL(rectangle.GetArea(), area);

	double perimeter = 2 * (width + height);
	BOOST_CHECK_EQUAL(rectangle.GetPerimeter(), perimeter);

	BOOST_CHECK_EQUAL(rectangle.GetOutlineColor(), "000fff");
	BOOST_CHECK_EQUAL(rectangle.GetFillColor(), "ff0000");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Create)
BOOST_AUTO_TEST_CASE(line)
{
	VerifyHandleCommand("line 0 0 2 5.5 ff0000",
		R"(Line segment:
area = 0.0000
perimeter = 5.8523
outline color = ff0000
)");
};

BOOST_AUTO_TEST_CASE(circle)
{
	VerifyHandleCommand("circle 0 0 5 ff0000 ff0000",
		R"(Circle:
area = 78.5398
perimeter = 31.4159
outline color = ff0000
fill color = ff0000
)");
};

BOOST_AUTO_TEST_CASE(rectangle)
{
	VerifyHandleCommand("rectangle 0 0 5 10 ff0000 ff0000",
		R"(Rectangle:
area = 50.0000
perimeter = 30.0000
outline color = ff0000
fill color = ff0000
)");
};

BOOST_AUTO_TEST_CASE(triangle)
{
	VerifyHandleCommand("triangle 0 0 2 2 0 2 ff0000 ff0000",
		R"(Triangle:
area = 2.0000
perimeter = 6.8284
outline color = ff0000
fill color = ff0000
)");
};
BOOST_AUTO_TEST_SUITE_END()
