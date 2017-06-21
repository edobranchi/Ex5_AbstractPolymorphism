/*
 * Polygon.h
 *
 */

#ifndef POLYGON_H_
#define POLYGON_H_

#include "Shape.h"
#include "Point.h"

class Polygon : public Shape {
public:
	explicit Polygon(int numPoints=10);	// TODO allocate points. If numPoints is zero or negative then set to 1
	virtual ~Polygon();// TODO implement destructor

	virtual bool draw() const;	// TODO draws only if there are >2 points that have notNeg points

	const Point* getPoint(int index) const;	// TODO implement. Return 0 if point is out of index
	bool setPoint(int index, const Point& point);	// TODO implement. Return false if trying to set Point out of bounds.

	int getMaxPoints() const;

private:
	Point* points;
	int maxPoints;
};

#endif /* POLYGON_H_ */
