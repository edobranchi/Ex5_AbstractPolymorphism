/*
 * Point.h
 *
 */

#ifndef POINT_H_
#define POINT_H_

struct Point {
	explicit Point(int ax=-1, int ay=-1) : x(ax), y(ay) {}
	int x;
	int y;
	//  implement inline method to return true if both coordinates are >= 0
	bool isNotNeg() const {
		if (x>=0 && y>=0){
			return true;
		}else return false;
	}
	// implement inline operator ==
	bool operator==(const Point& rh) const {
        return x == rh.x && y == rh.y;
	}
};



#endif /* POINT_H_ */
