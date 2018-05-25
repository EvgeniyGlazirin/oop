#include "stdafx.h"
#include "../Car/Car.h"
#include "../Car/DriveCar.h"
using boost::none;
using boost::optional;

struct DriveCarDependencies
{
	CCar car;
	std::stringstream input;
	std::stringstream output;
};

struct DriveCarFixture : DriveCarDependencies
{
	CDriveCar driveCar;

	DriveCarFixture()
		: driveCar(car, input, output)
	{
	}

	// Вспомогательная функция для проверки работы команды command
	void VerifyCommandHandling(const std::string& command, 
		const optional<int> & expectedGear, 
		const optional<int>& expectedSpeed, 
		const std::string& expectedOutput)
	{
		// Предварительно очищаем содержимое выходного потока
		output = std::stringstream();
		input = std::stringstream();
		BOOST_CHECK(input << command);
		BOOST_CHECK(driveCar.HandleCommand());
		BOOST_CHECK_EQUAL(car.GetGear(), expectedGear.get_value_or(0));
		BOOST_CHECK_EQUAL(car.GetSpeed(), expectedSpeed.get_value_or(0));
		BOOST_CHECK(input.eof());
		std::cout << output.str() << std::endl;
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
		
	}
};


BOOST_FIXTURE_TEST_SUITE(drive_car_controller, DriveCarFixture)

BOOST_AUTO_TEST_CASE(can_handle_EngineOn_command)
{
	VerifyCommandHandling("EngineOn", 0, 0, "");
}/*
BOOST_AUTO_TEST_CASE(unknown_command_will_call_error)
{
	VerifyCommandHandling("Command ", 0, 0, "  Unknown command!");
}
BOOST_AUTO_TEST_CASE(command_EngineOn_take_error_if_engine_turned_on_already)
{
	BOOST_CHECK(car.TurnOnEngine());
	VerifyCommandHandling("EngineOn", 0, 0, "  Error: Engine turned on already");
}
BOOST_AUTO_TEST_CASE(can_handle_EngineOff_command_when_engine_turn_on)
{
	BOOST_CHECK(car.TurnOnEngine());
	VerifyCommandHandling("EngineOff", 0, 0, "");
}
BOOST_AUTO_TEST_CASE(command_EngineOff_take_error_if_engine_turned_off_already)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.TurnOffEngine());
	VerifyCommandHandling("EngineOff", 0, 0, "");
}
BOOST_AUTO_TEST_CASE(can_set_gear_with_the_command_SetGear)
{
	BOOST_CHECK(car.TurnOnEngine());
	VerifyCommandHandling("SetGear 1", 1, 0, "");
}
BOOST_AUTO_TEST_CASE(command_SetGear_cant_set_wrong_gear_value)
{
	BOOST_CHECK(car.TurnOnEngine());
	VerifyCommandHandling("SetGear 4", 0, 0, "  Error: Invalid gear value");
}
BOOST_AUTO_TEST_CASE(can_set_speed_with_the_command_SetSpeed)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(1));
	VerifyCommandHandling("SetSpeed 10", 1, 10, "");
}
BOOST_AUTO_TEST_CASE(command_SetSpeed_cant_set_wrong_speed_value)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(1));
	VerifyCommandHandling("SetSpeed 50", 1, 0, "  Error: Invalid speed value");
}
*/
BOOST_AUTO_TEST_SUITE_END()
