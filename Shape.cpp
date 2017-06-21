/*
 * Shape.cpp
 *
 */

#include "Shape.h"

Shape::Shape() {
	topLeft = Point(-1, -1);
}

// TODO all shapes must provide a draw() method that has no arguments and return true if draw succeeded

Point Shape::getTopLeft() const {
	return topLeft;
}

void Shape::setTopLeft(Point topLeft) {
	this->topLeft = topLeft;
}

Shape::~Shape() {

}
