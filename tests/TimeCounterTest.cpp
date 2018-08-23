#include "TimeCounter.h"

//CppUTest includes should be after your and system includes
#include "CppUTest/TestHarness.h"

TEST_GROUP(TimeCounter) {
	TimeCounter* timeCounter;

	void setup() {
		timeCounter = new TimeCounter();
	}
	void teardown() {
		delete timeCounter;
	}
};

TEST(TimeCounter, increaseCount) {
	timeCounter->setLimit(5);

	LONGS_EQUAL(0, timeCounter->getTimeCount());
	timeCounter->increaseCount();
	LONGS_EQUAL(1, timeCounter->getTimeCount());
	timeCounter->increaseCount();
	LONGS_EQUAL(2, timeCounter->getTimeCount());
}

TEST(TimeCounter, rollover) {
	timeCounter->setLimit(3);

	timeCounter->increaseCount();
	timeCounter->increaseCount();
	timeCounter->increaseCount();
	LONGS_EQUAL(3, timeCounter->getTimeCount());
	timeCounter->increaseCount();
	LONGS_EQUAL(0, timeCounter->getTimeCount());
}

TEST(TimeCounter, overflow) {
	timeCounter->setLimit(3);

	bool overflow;

	overflow = timeCounter->increaseCount();
	CHECK_FALSE(overflow);
	overflow = timeCounter->increaseCount();
	CHECK_FALSE(overflow);
	overflow = timeCounter->increaseCount();
	CHECK_FALSE(overflow);
	overflow = timeCounter->increaseCount();
	CHECK_TRUE(overflow);
}

