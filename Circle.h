/*
 * Circle.h
 *
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"

class Circle : public Shape {
public:
	explicit Circle(int r);
		                           //  radius must be >0; if needed set to 1
	virtual ~Circle();

	virtual bool draw() const; // TODO draws if topLeft has >=0 coords.

	int getRadius() const;

private:
	int radius;
};

#endif /* CIRCLE_H_ */
