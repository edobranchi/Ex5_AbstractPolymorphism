/*
 * Shape.h
 *
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "Point.h"

class Shape {
public:
	Shape();
	virtual ~Shape();// implement destructor

	//  all shapes must provide a draw() method that has no arguments and return true if draw succeeded
    virtual bool draw() const=0;

	Point getTopLeft() const;
	void setTopLeft(Point topLeft);

protected:
	Point topLeft;
};

#endif /* SHAPE_H_ */
