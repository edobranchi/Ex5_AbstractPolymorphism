#ifndef TESTCIRCLE_H_
#define TESTCIRCLE_H_

#include <cxxtest/TestSuite.h>

#include "Circle.h"
#include "Point.h"

class TestCircle: public CxxTest::TestSuite {
public:
	void testCircle() {
		Circle c1(8);
		TS_ASSERT_EQUALS(c1.getRadius(), 8);
	}

	void testDraw() {
		Circle c1(8);
		Point p1(8, 9);
		c1.setTopLeft(p1);
		bool result = c1.draw();
		TS_ASSERT_EQUALS(result, true);
	}

};

#endif /*TESTCIRCLE_H_*/
