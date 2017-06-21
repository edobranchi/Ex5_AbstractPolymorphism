#ifndef TESTPOINT_H_
#define TESTPOINT_H_

#include <cxxtest/TestSuite.h>

#include "Point.h"

class TestPoint: public CxxTest::TestSuite {
public:
	void testPoint() {
		Point p1(2, 23);
		TS_ASSERT_EQUALS(p1.x, 2);
		TS_ASSERT_EQUALS(p1.y, 23);
		Point p2;
		TS_ASSERT_EQUALS(p2.x, -1);
		TS_ASSERT_EQUALS(p2.y, -1);
	}

	void testIsPos() {
		Point p1(2, 23);
		TS_ASSERT_EQUALS(p1.isNotNeg(), true);
		Point p2(2, -1);
		TS_ASSERT_EQUALS(p2.isNotNeg(), false);
	}

	void testOperator_equal() {
		Point p1(2, 23);
		Point p2(3, 4);
		TS_ASSERT_EQUALS(p1 == p2, false);
	}

};

#endif /*TESTPOINT_H_*/
