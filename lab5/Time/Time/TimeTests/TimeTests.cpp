// TimeTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Time/Time.h"

BOOST_AUTO_TEST_SUITE(class_CTime)

BOOST_AUTO_TEST_CASE(can_receive_seconds_as_argument)
{
	CTime timestamp(123);
	unsigned expectedResult = 123;
	BOOST_CHECK_EQUAL(timestamp.GetTimeStamp(), expectedResult);

	BOOST_CHECK_THROW(CTime time(1110000003), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(can_receive_hours_minutes_and_seconds_as_arguments)
{
	CTime timestamp(2, 39, 32);
	unsigned expectedResult = 9572;
	BOOST_CHECK_EQUAL(timestamp.GetTimeStamp(), expectedResult);

	BOOST_CHECK_THROW(CTime time(111, 25, 25), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(return_timestamp_value)
{
	CTime timestamp(122);
	unsigned expectedResult = 122;
	BOOST_CHECK_EQUAL(timestamp.GetTimeStamp(), expectedResult);
}

BOOST_AUTO_TEST_CASE(return_hours_value)
{
	CTime time(10000);
	unsigned expectedResult = 2;
	BOOST_CHECK_EQUAL(time.GetHours(), expectedResult);
}

BOOST_AUTO_TEST_CASE(return_minutes_value)
{
	CTime time(10000);
	unsigned expectedResult = 46;
	BOOST_CHECK_EQUAL(time.GetMinutes(), expectedResult);
}

BOOST_AUTO_TEST_CASE(return_seconds_value)
{
	CTime time(101);
	unsigned expectedResult = 41;
	BOOST_CHECK_EQUAL(time.GetSeconds(), expectedResult);
}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(class_CTime_have_overload)

BOOST_AUTO_TEST_CASE(operation_prefix_increment)
{
	CTime time(101);
	++time;
	unsigned expectedResult = 42;
	BOOST_CHECK_EQUAL(time.GetSeconds(), expectedResult);

	CTime timestamp2(86399);
	++timestamp2;
	unsigned expectedResult2 = 0;
	BOOST_CHECK_EQUAL(timestamp2.GetSeconds(), expectedResult2);
}

BOOST_AUTO_TEST_CASE(operation_postfix_increment)
{
	CTime time(101);
	time++;
	unsigned expectedResult = 42;
	BOOST_CHECK_EQUAL(time.GetSeconds(), expectedResult);

	CTime time2(86399);
	time2++;
	unsigned expectedResult2 = 0;
	BOOST_CHECK_EQUAL(time2.GetSeconds(), expectedResult2);
}

BOOST_AUTO_TEST_CASE(operation_prefix_decrement)
{
	CTime time(101);
	--time;
	unsigned expectedResult = 40;
	BOOST_CHECK_EQUAL(time.GetSeconds(), expectedResult);

	CTime timestamp2(0);
	--timestamp2;
	unsigned expectedResult2 = 86399;
	BOOST_CHECK_EQUAL(timestamp2.GetTimeStamp(), expectedResult2);
}

BOOST_AUTO_TEST_CASE(operation_postfix_decrement)
{
	CTime time(101);
	time--;
	unsigned expectedResult = 40;
	BOOST_CHECK_EQUAL(time.GetSeconds(), expectedResult);

	CTime time2(0);
	time2--;
	unsigned expectedResult2 = 86399;
	BOOST_CHECK_EQUAL(time2.GetTimeStamp(), expectedResult2);

}
BOOST_AUTO_TEST_CASE(operation_plus)
{
	CTime time(44001);
	CTime time2(80004);
	CTime resultOfSumTimes = time + time2;
	unsigned expectedResult = 37605;
	BOOST_CHECK_EQUAL(resultOfSumTimes.GetTimeStamp(), expectedResult);
}

BOOST_AUTO_TEST_CASE(operation_minus)
{
	CTime time(300);
	CTime time2(400);
	CTime resultOfSumTimes = time- time2;
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
	CTime time(66000);
	CTime time2(30300);
	time += time2;
	unsigned expectedResult = 9900;
	BOOST_CHECK_EQUAL(time.GetTimeStamp(), expectedResult);
}

BOOST_AUTO_TEST_CASE(operation_minus_equal)
{
	CTime time(300);
	CTime time2(200);
	time -= time2;
	unsigned expectedResult = 100;
	BOOST_CHECK_EQUAL(time.GetTimeStamp(), expectedResult);

	CTime time3(200);
	CTime time4(300);
	time3 -= time4;
	unsigned expectedResult2 = 86300;
	BOOST_CHECK_EQUAL(time3.GetTimeStamp(), expectedResult2);
}

BOOST_AUTO_TEST_CASE(operation_multiply)
{
	CTime time(101);
	CTime result = time * 3;
	unsigned expectedResult = 303;
	BOOST_CHECK_EQUAL(result.GetTimeStamp(), expectedResult);

}

BOOST_AUTO_TEST_CASE(operation_division)
{
	CTime time(101);
	CTime result = time / 3;
	unsigned expectedResult = 33;
	BOOST_CHECK_EQUAL(result.GetTimeStamp(), expectedResult);

	CTime time2(10001);
	CTime time21(123);
	unsigned result2 = time2 / time21;
	unsigned expectedResult2 = 81;
	BOOST_CHECK_EQUAL(result2, expectedResult2);

	CTime time3(123);
	CTime zeroTime(0);
	BOOST_CHECK_THROW((time3/zeroTime), std::invalid_argument);

	CTime time4(123);
	BOOST_CHECK_THROW((time4 / 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(operation_multiply_equal)
{
	CTime time(101);
	time *= 3;
	unsigned expectedResult = 303;
	BOOST_CHECK_EQUAL(time.GetTimeStamp(), expectedResult);
}

BOOST_AUTO_TEST_CASE(operation_division_equal)
{
	CTime timestamp(101);
	timestamp /= 3;
	unsigned expectedResult = 33;
	BOOST_CHECK_EQUAL(timestamp.GetTimeStamp(), expectedResult);

	CTime time4(123);
	BOOST_CHECK_THROW((time4 /= 0), std::invalid_argument);
	}

BOOST_AUTO_TEST_CASE(operation_equal)
{
	CTime time(101);
	CTime time2(101);
	CTime time3(100);
	BOOST_CHECK(time == time2);
	BOOST_CHECK(!(time == time3));
}

BOOST_AUTO_TEST_CASE(operation_not_equal)
{
	CTime time(101);
	CTime time2(101);
	CTime time3(100);
	BOOST_CHECK(time != time3);
	BOOST_CHECK(!(time != time2));
}

BOOST_AUTO_TEST_CASE(operation_more)
{
	CTime time(101);
	CTime time2(100);
	CTime time3(101);
	BOOST_CHECK(time > time2);
	BOOST_CHECK(!(time2 > time));
	BOOST_CHECK(!((time3 > time) && (time3 == time)));
}

BOOST_AUTO_TEST_CASE(operation_less)
{
	CTime time(101);
	CTime time2(102);
	CTime time3(102);
	BOOST_CHECK(time < time2);
	BOOST_CHECK(!(time2 < time));
	BOOST_CHECK(!((time2 < time3) && (time2 == time3)));
}

BOOST_AUTO_TEST_CASE(operation_more_or_equal)
{
	CTime time(101);
	CTime time2(100);
	BOOST_CHECK(time >= time2);
	CTime time3(100);
	CTime time4(100);
	BOOST_CHECK(time3 >= time4);
	CTime time5(100);
	CTime time6(101);
	BOOST_CHECK(!(time5 >= time6));
}

BOOST_AUTO_TEST_CASE(operation_less_or_equal)
{
	CTime time(100);
	CTime time2(101);
	BOOST_CHECK(time <= time2);
	CTime time3(101);
	CTime time4(101);
	BOOST_CHECK(time3 <= time4);
	CTime time5(101);
	CTime time6(100);
	BOOST_CHECK(!(time5 <= time6));
}
BOOST_AUTO_TEST_SUITE_END()


