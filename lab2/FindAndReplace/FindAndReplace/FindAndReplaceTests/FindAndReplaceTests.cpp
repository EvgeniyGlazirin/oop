#include "stdafx.h"
#include "../FindAndReplace/FindAndReplace.h"

TEST_CASE("FindAndReplace test")
{
	CHECK(FindAndReplace("", "", "") == "");
	CHECK(FindAndReplace("Example string", "", "") == "Example string");
	CHECK(FindAndReplace("Example string", "", "Example") == "Example string");
	CHECK(FindAndReplace("Example string", "Example", "Result") == "Result string");
	CHECK(FindAndReplace("Example string Example string", "Example", "Result") 
		== "Result string Result string");
}
