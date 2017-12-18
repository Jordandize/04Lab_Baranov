#include "Segment.h"
#include <cmath>
#include <iostream>

int Segment::_freeID = 0;

double Segment::length () const
{
	// c^2 = a^2 + b^2;
	return sqrt((endX() - startX()) * (endX() - startX()) 
		      + (endY() - startY()) * (endY() - startY()));
}

double Segment::distance (const Point& point) const
{
	return abs((endY() - startY()) * point.x()				//  |(y2 - y1) * x0
			 - (endX() - startX()) * point.y()				// - (x2 - x1) * y0
			 +  endX() * startY() - endY() * startX())      // + x2*y1 - y2*x1|
			 / length();									// / (c^2 = a^2 + b^2) (length of segment);
}

const Point &Segment::middle() const
{
	if(_middle == 0)
		_middle = new Point((endX() + startX()) / 2., (endY() + startY()) / 2.);
	return *_middle;
}

ostream& operator<<(ostream & os, const Segment& seg)
{
	os << "Segment " << seg.start() << seg.end();
	return os;
}