/*
 * Polygon.cpp
 *
 */

#include "Polygon.h"
#include <iostream>

Polygon::Polygon(int numPoints) {
	if(numPoints<=0) {
		numPoints = 1;
	}
maxPoints=numPoints ;
points=new Point[maxPoints];}
	// allocate points. If numPoints is zero or negative then set to 1

Polygon::~Polygon() {
	if(points){
		delete[] points;
	}
}

bool Polygon::draw() const {
	int i=0;
	for (int count=0; count<maxPoints;count++){
		if(points[count].isNotNeg()){
			i++;
		}
	}
	if(i<=2){
		return false;
	}else return true;//draws only if there are >2 points that have notNeg points
}

const Point* Polygon::getPoint(int index) const {
	if(index<=maxPoints){
		return &points[index];
	}
	else return 0;// TODO implement. Return 0 if point is out of index
}

bool Polygon::setPoint(int index, const Point& point) {
	if (index<=maxPoints){
		points[index]=point;
		return true;
	}
	else return false;// TODO implement. Return false if trying to set Point out of bounds.
}

int Polygon::getMaxPoints() const  {
	return maxPoints;
}
