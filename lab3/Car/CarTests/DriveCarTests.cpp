#include "stdafx.h"

#include "../Car/DriveCar.h"
using boost::none;
using boost::optional;

struct DriveCarDependencies
{
	std::stringstream input;
	std::stringstream output;
};

struct DriveCarFixture : DriveCarDependencies
{
	CDriveCar driveCar;

	DriveCarFixture()
		: driveCar(input, output)
	{
	}

	// Вспомогательная функция для проверки работы команды command
	void VerifyCommandHandling(const std::string& command, 
		const optional<bool> & expectedEngineStatus,
		const optional<int> & expectedGear, 
		const optional<int>& expectedSpeed, 
		const std::string& expectedOutput)
	{
		// Предварительно очищаем содержимое выходного потока
		output = std::stringstream();
		input = std::stringstream();
		BOOST_CHECK(input << command);
		BOOST_CHECK(driveCar.HandleCommand());
		BOOST_CHECK_EQUAL(driveCar.IsEngineTurnedOn(), expectedEngineStatus.is_initialized());
		BOOST_CHECK_EQUAL(driveCar.GetGear(), expectedGear.get_value_or(0));
		BOOST_CHECK_EQUAL(driveCar.GetSpeed(), expectedSpeed.get_value_or(0));
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
		
	}
};


BOOST_FIXTURE_TEST_SUITE(drive_car_controller, DriveCarFixture)
BOOST_AUTO_TEST_CASE(can_handle_EngineOn_command)
{
	VerifyCommandHandling("EngineOn", true, 0, 0, "");
}
BOOST_AUTO_TEST_SUITE_END()
