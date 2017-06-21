//
// Created by Edoardo on 21/06/2017.
//
#include <iostream>
#include "Circle.h"
#include "Polygon.h"
#include "Rectangle.h"

void TS_ASSERT(bool a){
    if (!a){
        std::cerr<<"errore"<<std::endl;
    }
}

void TS_ASSERT_EQUALS(int a, int b){
    if (a!=b){
        std::cerr<<"errore 2"<<std::endl;
    }
}
namespace circle{
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
}
namespace polygon{
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
}

namespace rectangle{
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

}

namespace point{
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
}

namespace poli{
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
}

int main() {
    rectangle::testRectangle();
    rectangle::testDraw();
    point::testPoint();
    point::testIsPos();
    point::testOperator_equal();
    circle::testDraw();
    circle::testCircle();
    polygon::testDraw();
    polygon::testGetSetPoint();
    polygon::testPolygon();
    poli::testPolymorphic_MemoryLeak();
}
