// CarTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
 #include "../Car/Car.h"

struct CarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(car, CarFixture)
	BOOST_AUTO_TEST_CASE(engine_turned_off_by_default)
	{
		BOOST_CHECK(!car.IsEngineTurnedOn());
	}
	BOOST_AUTO_TEST_CASE(turned_off_engine_can_be_turn_on)
	{
		car.TurnOnEngine();
		BOOST_CHECK(car.IsEngineTurnedOn());
	}
	BOOST_AUTO_TEST_CASE(engine_cant_be_turn_on_if_turned_on_already)
	{
		car.TurnOnEngine();
		BOOST_CHECK(!car.TurnOnEngine());
	}
	BOOST_AUTO_TEST_CASE(engine_can_be_turn_off_if_it_turned_on)
	{
		car.TurnOnEngine();
		car.TurnOffEngine();
		BOOST_CHECK(!car.IsEngineTurnedOn());
	}
	BOOST_AUTO_TEST_CASE(engine_cant_be_turn_off_if_turned_off_already)
	{
		car.TurnOnEngine();
		car.TurnOffEngine();
		BOOST_CHECK(!car.TurnOffEngine());
	}
BOOST_AUTO_TEST_SUITE_END()