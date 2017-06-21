#ifndef TESTPOLYGON_H_
#define TESTPOLYGON_H_

#include <cxxtest/TestSuite.h>

#include "Polygon.h"
#include "Point.h"
#include "Shape.h"

class TestPolygon : public CxxTest::TestSuite {
public:
	void testPolygon() {
		Polygon pol1(5);
		TS_ASSERT_EQUALS(pol1.getMaxPoints(), 5);
		Shape* pS = new Polygon(4);
		delete pS;
	}

	void testDraw() {
		Polygon pol1(6);
		Point p1(3, 4);
		Point p2(4, 5);
		Point p3(65, 78);
		Point p4(89, 34);
		Point p5(34, 21);
		pol1.setPoint(0, p1);
		pol1.setPoint(1, p2);
		pol1.setPoint(2, p3);
		pol1.setPoint(3, p4);
		pol1.setPoint(4, p5);
		bool result = pol1.draw();
		TS_ASSERT_EQUALS(result, true);
	}

	void testGetSetPoint() {
		Polygon pol1(6);
		Point p1(3, 4);
		Point p2(4, 5);
		pol1.setPoint(0, p1);
		pol1.setPoint(1, p2);
		TS_ASSERT(p1 == (*pol1.getPoint(0)));
		TS_ASSERT(p2 == (*pol1.getPoint(1)));
		TS_ASSERT(0 == pol1.getPoint(12));
	}

};

#endif /*TESTPOLYGON_H_*/
