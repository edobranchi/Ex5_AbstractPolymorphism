/*
 * Circle.cpp
 *
 */

#include "Circle.h"

Circle::Circle(int r){
	if (r <=0){
		r=1;
	}
	radius=r;
}                              // radius must be >0; if needed set to 1


Circle::~Circle() {
}

bool Circle::draw() const {
	if(topLeft.isNotNeg())
	{
		return true;
	}else return false;
	// draws if topLeft has >=0 coords.
}

int Circle::getRadius() const {
	return radius;
}
