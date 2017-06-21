#ifndef TESTRECTANGLE_H_
#define TESTRECTANGLE_H_

#include <cxxtest/TestSuite.h>

#include "Rectangle.h"
#include "Shape.h"

class TestRectangle: public CxxTest::TestSuite {
public:
	void testRectangle() {
		Point p1(2, 3);
		Point p2(4, 8);
		Rectangle r1(p1, p2);
		TS_ASSERT(r1.getTopLeft() == p1);
		TS_ASSERT(r1.getBottomRight() == p2);
		Shape* pS = new Rectangle();
		delete pS;
		pS = new Rectangle(p1, p2);
		delete pS;
	}

	void testDraw() {
		Point p1(2, 3);
		Point p2(4, 8);
		Rectangle r1(p1, p2);
		bool result = r1.draw();
		TS_ASSERT_EQUALS(result, true);
	}

};

#endif /*TESTRECTANGLE_H_*/
