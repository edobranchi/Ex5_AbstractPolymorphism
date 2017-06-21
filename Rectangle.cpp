/*
 * Rectangle.cpp
 *
 */

#include "Rectangle.h"

Rectangle::Rectangle(const Point& tl, const Point& br){
	// TODO implement
    topLeft=tl;
    bottomRight=br;
}

Rectangle::~Rectangle() {
}

bool Rectangle::draw() const {
    return bottomRight.isNotNeg() && topLeft.isNotNeg();
}
    //  implement draw(). Draws only if top left and bottom right points are notNeg


// TODO provide getter/setter methods for bottomRight
