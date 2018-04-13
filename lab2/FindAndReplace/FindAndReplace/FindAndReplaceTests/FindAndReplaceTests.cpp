#include "stdafx.h"
#include "../FindAndReplace/FindAndReplace.h"

TEST_CASE("function FindAndReplace dont change input string if search string is empty")
{
	CHECK(FindAndReplace("Example string", "", "") == "Example string");
}

TEST_CASE("function FindAndReplace changing search string and replace empty string")
{
	CHECK(FindAndReplace("Example string", "Example", "") == " string");
}

TEST_CASE("function FindAndReplace changing input string and replace string as expected")
{
	CHECK(FindAndReplace("Example string", "Example", "Result") == "Result string");
}

TEST_CASE("function FindAndReplace changing several values as expected")
{
	CHECK(FindAndReplace("Example string Example string", "Example", "Result")
		== "Result string Result string");
}


