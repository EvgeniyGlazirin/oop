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

	BOOST_AUTO_TEST_CASE(engine_cant_be_turn_off_if_turned_off_already)
	{
		car.TurnOnEngine();
		car.TurnOffEngine();
		BOOST_CHECK(!car.TurnOffEngine());
	}
	BOOST_AUTO_TEST_CASE(speed_cant_be_set_if_engine_turned_off)
	{
		BOOST_CHECK(!car.SetSpeed(10));
	}
BOOST_AUTO_TEST_SUITE_END()

	struct CarWithEngineTurnedOn : CarFixture
	{
		CarWithEngineTurnedOn()
		{
			car.TurnOnEngine();
		}
	};

	BOOST_FIXTURE_TEST_SUITE(when_engine_turned_on, CarWithEngineTurnedOn)
		BOOST_AUTO_TEST_CASE(engine_can_be_turn_off)
		{
			car.TurnOffEngine();
			BOOST_CHECK(!car.IsEngineTurnedOn());
		}
		BOOST_AUTO_TEST_CASE(engine_cant_be_turn_off_when_speed_or_gear_not_equals_0)
		{
			BOOST_CHECK(car.SetGear(1));
			BOOST_CHECK(!car.TurnOffEngine());
			BOOST_CHECK(car.SetSpeed(10));
			BOOST_CHECK(car.SetGear(0));
			BOOST_CHECK(!car.TurnOffEngine());
		}
		BOOST_AUTO_TEST_CASE(engine_cant_be_turn_on_if_turned_on_already)
		{
			BOOST_CHECK(!car.TurnOnEngine());
		}

	BOOST_FIXTURE_TEST_SUITE(set_gear, CarWithEngineTurnedOn)
		BOOST_AUTO_TEST_CASE(gear_is_neitral_by_default)
		{
			BOOST_CHECK(car.GetGear() == 0);
		}
		BOOST_AUTO_TEST_CASE(gear_cant_be_changed_when_engine_off)
		{
			BOOST_CHECK(car.TurnOffEngine());
			BOOST_CHECK(!car.IsEngineTurnedOn());
			BOOST_CHECK(!car.SetGear(1));
		}
		BOOST_AUTO_TEST_CASE(gear_cant_be_changed_to_reverse_when_speed_not_equals_0)
		{
			BOOST_CHECK(car.SetGear(1));
			BOOST_CHECK(car.SetSpeed(10));
			BOOST_CHECK(!car.SetGear(-1));
		}
		BOOST_AUTO_TEST_CASE(cant_set_not_existing_gear)
		{
			BOOST_CHECK(!car.SetGear(6));
			BOOST_CHECK(!car.SetGear(-2));
		}
		BOOST_AUTO_TEST_CASE(reverse_gear_can_be_set_when_speed_equals_0_only)
		{
			BOOST_CHECK(car.SetSpeed(0));
			BOOST_CHECK(car.SetGear(-1));
		}
		BOOST_AUTO_TEST_CASE(switch_gear_to_new_can_be_done_with_allow_speed_for_new_gear)
		{
			BOOST_CHECK(car.SetGear(1));
			BOOST_CHECK(car.SetSpeed(20));
			BOOST_CHECK(car.SetGear(2));
			BOOST_CHECK(car.SetSpeed(25));
			BOOST_CHECK(!car.SetGear(5));
		}
		BOOST_AUTO_TEST_CASE(switch_gear_from_reverse_to_first_can_be_done_with_speed_equals_0)
		{
			BOOST_CHECK(car.SetGear(-1));
			BOOST_CHECK(car.SetSpeed(20));
			BOOST_CHECK(!car.SetGear(1));
		}
		BOOST_AUTO_TEST_CASE(change_direction_will_be_done_only_after_stop)
		{
			BOOST_CHECK(car.SetGear(-1));
			BOOST_CHECK(car.SetSpeed(20));
			BOOST_CHECK(car.GetDirection() == CCar::Direction::Back);
			BOOST_CHECK(car.SetGear(0));
			BOOST_CHECK(car.GetDirection() == CCar::Direction::Back);
			BOOST_CHECK(!car.SetGear(1));
			BOOST_CHECK(car.SetSpeed(0));
			BOOST_CHECK(car.GetDirection() == CCar::Direction::Stop);
			BOOST_CHECK(car.SetGear(1));
			BOOST_CHECK(car.SetSpeed(10));
			BOOST_CHECK(car.GetDirection() == CCar::Direction::Forward);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_FIXTURE_TEST_SUITE(set_speed, CarWithEngineTurnedOn)
		BOOST_AUTO_TEST_CASE(speed_equals_0_by_default)
		{
			BOOST_CHECK(car.GetSpeed() == 0);
		}
		BOOST_AUTO_TEST_CASE(cant_change_speed_when_engine_turn_off)
		{
			car.TurnOffEngine();
			BOOST_CHECK(!car.SetSpeed(10));
		}
		BOOST_AUTO_TEST_CASE(speed_cant_be_negative)
		{
			BOOST_CHECK(!car.SetSpeed(-10));
		}
		BOOST_AUTO_TEST_CASE(speed_cant_be_more_than_maximum_speed_in_reverse_gear)
		{
			BOOST_CHECK(car.SetGear(-1));
			BOOST_CHECK(!car.SetSpeed(21));
		}
		BOOST_AUTO_TEST_CASE(cant_set_speed_greater_than_current_on_neitral_gear)
		{
			BOOST_CHECK(car.SetSpeed(0));
			BOOST_CHECK(car.SetGear(0));
			BOOST_CHECK(!car.SetSpeed(10));
		}
		BOOST_AUTO_TEST_CASE(change_speed_can_be_done_if_new_speed_sitable_for_gear)
		{
			BOOST_CHECK(car.SetGear(1));
			BOOST_CHECK(car.SetSpeed(20));
			BOOST_CHECK(car.SetGear(2));
			BOOST_CHECK(!car.SetSpeed(125));
		}

BOOST_AUTO_TEST_SUITE_END()
}