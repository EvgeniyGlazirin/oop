// TimeTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Time/Time.h"

BOOST_AUTO_TEST_SUITE(class_CTime)
/*
BOOST_AUTO_TEST_CASE(return_error_if_input_value_more_than_max_seconds_value_in_a_day)
{
	BOOST_CHECK(CTime timestamp(1221212));
}
*/

BOOST_AUTO_TEST_CASE(can_receive_seconds_as_argument)
{
	CTime timestamp(123);
	unsigned expectedResult = 123;
	BOOST_CHECK_EQUAL(timestamp.GetTimeStamp(), expectedResult);
}

BOOST_AUTO_TEST_CASE(can_receive_hours_minutes_and_seconds_as_arguments)
{
	CTime timestamp(2, 39, 32);
	unsigned expectedResult = 9572;
	BOOST_CHECK_EQUAL(timestamp.GetTimeStamp(), expectedResult);
}

BOOST_AUTO_TEST_CASE(return_timestamp_value)
{
	CTime timestamp(122);
	unsigned expectedResult = 122;
	BOOST_CHECK_EQUAL(timestamp.GetTimeStamp(), expectedResult);
}

BOOST_AUTO_TEST_CASE(return_hours_value)
{
	CTime timestamp(10000);
	unsigned expectedResult = 2;
	BOOST_CHECK_EQUAL(timestamp.GetHours(), expectedResult);
}

BOOST_AUTO_TEST_CASE(return_minutes_value)
{
	CTime timestamp(10000);
	unsigned expectedResult = 46;
	BOOST_CHECK_EQUAL(timestamp.GetMinutes(), expectedResult);
}

BOOST_AUTO_TEST_CASE(return_seconds_value)
{
	CTime timestamp(101);
	unsigned expectedResult = 41;
	BOOST_CHECK_EQUAL(timestamp.GetSeconds(), expectedResult);
}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(class_CTime_have_overload)

BOOST_AUTO_TEST_CASE(operation_prefix_increment)
{
	CTime timestamp(101);
	++timestamp;
	unsigned expectedResult = 42;
	BOOST_CHECK_EQUAL(timestamp.GetSeconds(), expectedResult);

	CTime timestamp2(86399);
	++timestamp2;
	unsigned expectedResult2 = 0;
	BOOST_CHECK_EQUAL(timestamp2.GetSeconds(), expectedResult2);
}

BOOST_AUTO_TEST_CASE(operation_postfix_increment)
{
	CTime timestamp(101);
	timestamp++;
	unsigned expectedResult = 42;
	BOOST_CHECK_EQUAL(timestamp.GetSeconds(), expectedResult);

	CTime timestamp2(86399);
	timestamp2++;
	unsigned expectedResult2 = 0;
	BOOST_CHECK_EQUAL(timestamp2.GetSeconds(), expectedResult2);
}

BOOST_AUTO_TEST_CASE(operation_prefix_decrement)
{
	CTime timestamp(101);
	--timestamp;
	unsigned expectedResult = 40;
	BOOST_CHECK_EQUAL(timestamp.GetSeconds(), expectedResult);

	CTime timestamp2(0);
	--timestamp2;
	unsigned expectedResult2 = 86399;
	BOOST_CHECK_EQUAL(timestamp2.GetTimeStamp(), expectedResult2);
}

BOOST_AUTO_TEST_CASE(operation_postfix_decrement)
{
	CTime timestamp(101);
	timestamp--;
	unsigned expectedResult = 40;
	BOOST_CHECK_EQUAL(timestamp.GetSeconds(), expectedResult);

	CTime timestamp2(0);
	timestamp2--;
	unsigned expectedResult2 = 86399;
	BOOST_CHECK_EQUAL(timestamp2.GetTimeStamp(), expectedResult2);

}
BOOST_AUTO_TEST_CASE(operation_plus)
{
	CTime timestamp(44001);
	CTime timestamp2(80004);
	CTime resultOfSumTimes = timestamp + timestamp2;
	unsigned expectedResult = 37605;
	BOOST_CHECK_EQUAL(resultOfSumTimes.GetTimeStamp(), expectedResult);
}

BOOST_AUTO_TEST_CASE(operation_minus)
{
	CTime timestamp(300);
	CTime timestamp2(400);
	CTime resultOfSumTimes = timestamp - timestamp2;
	unsigned expectedResult = 86300;
	BOOST_CHECK_EQUAL(resultOfSumTimes.GetTimeStamp(), expectedResult);

	CTime timestamp3(400);
	CTime timestamp4(300);
	CTime resultOfSumTimes2 = timestamp3 - timestamp4;
	unsigned expectedResult2 = 100;
	BOOST_CHECK_EQUAL(resultOfSumTimes2.GetTimeStamp(), expectedResult2);
}

BOOST_AUTO_TEST_CASE(operation_plus_equal)
{
	CTime timestamp(66000);
	CTime timestamp2(30300);
	timestamp += timestamp2;
	unsigned expectedResult = 9900;
	BOOST_CHECK_EQUAL(timestamp.GetTimeStamp(), expectedResult);
}

BOOST_AUTO_TEST_CASE(operation_minus_equal)
{
	CTime timestamp(300);
	CTime timestamp2(200);
	timestamp -= timestamp2;
	unsigned expectedResult = 100;
	BOOST_CHECK_EQUAL(timestamp.GetTimeStamp(), expectedResult);

	CTime timestamp3(200);
	CTime timestamp4(300);
	timestamp3 -= timestamp4;
	unsigned expectedResult2 = 86300;
	BOOST_CHECK_EQUAL(timestamp3.GetTimeStamp(), expectedResult2);
}

BOOST_AUTO_TEST_CASE(operation_multiply)
{
	CTime timestamp(101);
	CTime result = timestamp * 3;
	unsigned expectedResult = 303;
	BOOST_CHECK_EQUAL(result.GetTimeStamp(), expectedResult);
}

BOOST_AUTO_TEST_CASE(operation_division)
{
	CTime timestamp(101);
	CTime result = timestamp / 3;
	unsigned expectedResult = 33;
	BOOST_CHECK_EQUAL(result.GetTimeStamp(), expectedResult);

	CTime timestamp2(10001);
	CTime time2(123);
	unsigned result2 = timestamp2 / time2;
	unsigned expectedResult2 = 81;
	BOOST_CHECK_EQUAL(result2, expectedResult2);
	/*
	CTime timestamp3(123);
	BOOST_CHECK(!(timestamp3.GetTimeStamp() / 0));
	*/
}

BOOST_AUTO_TEST_CASE(operation_multiply_equal)
{
	CTime timestamp(101);
	timestamp *= 3;
	unsigned expectedResult = 303;
	BOOST_CHECK_EQUAL(timestamp.GetTimeStamp(), expectedResult);
}

BOOST_AUTO_TEST_CASE(operation_division_equal)
{
	CTime timestamp(101);
	timestamp /= 3;
	unsigned expectedResult = 33;
	BOOST_CHECK_EQUAL(timestamp.GetTimeStamp(), expectedResult);
}

BOOST_AUTO_TEST_CASE(operation_equal)
{
	CTime timestamp(101);
	CTime timestamp2(101);
	BOOST_CHECK_EQUAL(timestamp.GetTimeStamp(), timestamp2.GetTimeStamp());
}

BOOST_AUTO_TEST_CASE(operation_not_equal)
{
	CTime timestamp(101);
	CTime timestamp2(102);
	BOOST_CHECK(timestamp.GetTimeStamp() != timestamp2.GetTimeStamp());
}

BOOST_AUTO_TEST_CASE(operation_more)
{
	CTime timestamp(101);
	CTime timestamp2(100);
	BOOST_CHECK(timestamp.GetTimeStamp() > timestamp2.GetTimeStamp());
}

BOOST_AUTO_TEST_CASE(operation_little)
{
	CTime timestamp(101);
	CTime timestamp2(102);
	BOOST_CHECK(timestamp.GetTimeStamp() < timestamp2.GetTimeStamp());
}

BOOST_AUTO_TEST_CASE(operation_more_or_equal)
{
	CTime timestamp(101);
	CTime timestamp2(100);
	BOOST_CHECK(timestamp.GetTimeStamp() >= timestamp2.GetTimeStamp());
	CTime timestamp3(100);
	CTime timestamp4(100);
	BOOST_CHECK(timestamp3.GetTimeStamp() >= timestamp4.GetTimeStamp());
	CTime timestamp5(100);
	CTime timestamp6(101);
	BOOST_CHECK(!(timestamp5.GetTimeStamp() >= timestamp6.GetTimeStamp()));
}

BOOST_AUTO_TEST_CASE(operation_little_or_equal)
{
	CTime timestamp(100);
	CTime timestamp2(101);
	BOOST_CHECK(timestamp.GetTimeStamp() <= timestamp2.GetTimeStamp());
	CTime timestamp3(101);
	CTime timestamp4(101);
	BOOST_CHECK(timestamp3.GetTimeStamp() <= timestamp4.GetTimeStamp());
	CTime timestamp5(101);
	CTime timestamp6(100);
	BOOST_CHECK(!(timestamp5.GetTimeStamp() <= timestamp6.GetTimeStamp()));
}
BOOST_AUTO_TEST_SUITE_END()

