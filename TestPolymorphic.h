#ifndef TESTPOLYMORPHIC_H_
#define TESTPOLYMORPHIC_H_

#include <cxxtest/TestSuite.h>

#include "Polygon.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Point.h"
#include "Shape.h"

class TestPolymorphic : public CxxTest::TestSuite {
public:

	void testPolymorphic_MemoryLeak() {
		Shape* pol1 = new Polygon(6);
		Point p1(3, 4);
		Point p2(4, 5);
		Point p3(65, 78);
		Point p4(89, 34);
		Point p5(34, 21);
		static_cast<Polygon*>(pol1)->setPoint(0, p1);
		static_cast<Polygon*>(pol1)->setPoint(1, p2);
		static_cast<Polygon*>(pol1)->setPoint(2, p3);
		static_cast<Polygon*>(pol1)->setPoint(3, p4);
		static_cast<Polygon*>(pol1)->setPoint(4, p5);

		Shape* r1 = new Rectangle(p1, p2);
		Shape* c1 = new Circle(3);
		c1->setTopLeft(p3);

		Shape* shapes[3];
		shapes[0] = c1;
		shapes[1] = pol1;
		shapes[2] = r1;
		for (int i=0; i<3; i++) {
			bool result = shapes[i]->draw();
			TS_ASSERT_EQUALS(result, true);
		}
		delete pol1;
		delete r1;
		delete c1;
	}

};

#endif /*TESTPOLYMORPHIC_H_*/
