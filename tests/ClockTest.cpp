#include "Clock.h"
#include "Timer.h"
#include "MockSystemClock.h"

//CppUTest includes should be after your and system includes
#include "CppUTest/TestHarness.h"

TEST_GROUP(Clock) {
	ranetos::MockSystemClock* mockSystemClock;
	ranetos::Timer* timer;
	Clock* clock;

	void setup() {
		mockSystemClock = new ranetos::MockSystemClock();
		timer = new ranetos::Timer(*mockSystemClock);
		clock = new Clock(*timer);
	}
	void teardown() {
		delete clock;
		delete timer;
		delete mockSystemClock;
	}

	void increaseSecond() {
		mockSystemClock->setMillisecondsValue(mockSystemClock->getMillisecondsValue() + 1001);
		clock->work();
	}

	void increaseMinute() {
		for (int i = 0; i < 60; i++) {
			increaseSecond();
		}
	}

	void increaseHour() {
		for (int j = 0; j < 60; j++) {
			increaseMinute();
		}
	}
};


TEST(Clock, startZeroes) {
	clock->work();
	LONGS_EQUAL(0, clock->currentHour());
	LONGS_EQUAL(0, clock->currentMinute());
	LONGS_EQUAL(0, clock->currentSecond());
}

TEST(Clock, secondsAdvance) {
	increaseSecond();

	LONGS_EQUAL(0, clock->currentHour());
	LONGS_EQUAL(0, clock->currentMinute());
	LONGS_EQUAL(1, clock->currentSecond());
}

TEST(Clock, secondsAdvanceOverflow) {
	for (int i=0; i < 59; i++) {
		increaseSecond();
	}

	LONGS_EQUAL(0, clock->currentHour());
	LONGS_EQUAL(0, clock->currentMinute());
	LONGS_EQUAL(59, clock->currentSecond());

	increaseSecond();

	LONGS_EQUAL(0, clock->currentHour());
	LONGS_EQUAL(1, clock->currentMinute());
	LONGS_EQUAL(0, clock->currentSecond());
}

TEST(Clock, minutesAdvance) {
	increaseMinute();

	LONGS_EQUAL(0, clock->currentHour());
	LONGS_EQUAL(1, clock->currentMinute());
	LONGS_EQUAL(0, clock->currentSecond());
}

TEST(Clock, minutesAdvanceOverflow) {
	for (int i=0; i < 59; i++) {
		increaseMinute();
	}

	LONGS_EQUAL(0, clock->currentHour());
	LONGS_EQUAL(59, clock->currentMinute());
	LONGS_EQUAL(0, clock->currentSecond());

	increaseMinute();

	LONGS_EQUAL(1, clock->currentHour());
	LONGS_EQUAL(0, clock->currentMinute());
	LONGS_EQUAL(0, clock->currentSecond());
}

TEST(Clock, hoursAdvance) {
	increaseHour();

	LONGS_EQUAL(1, clock->currentHour());
	LONGS_EQUAL(0, clock->currentMinute());
	LONGS_EQUAL(0, clock->currentSecond());
}

TEST(Clock, hoursAdvanceOverflow) {
	for (int i=0; i < 23; i++) {
		increaseHour();
	}

	LONGS_EQUAL(23, clock->currentHour());
	LONGS_EQUAL(0, clock->currentMinute());
	LONGS_EQUAL(0, clock->currentSecond());

	increaseHour();

	LONGS_EQUAL(0, clock->currentHour());
	LONGS_EQUAL(0, clock->currentMinute());
	LONGS_EQUAL(0, clock->currentSecond());
}
