#include "Point.h"
#include <iostream>
using namespace std;

//init static field of class Point
int Point::freeID = 0;

ostream& operator<<(ostream& os, const Point& p)
{
	os << '(' << p.x() << ',' << p.y() << ')';
	return os;
}

const Point operator+(const Point& u, const Point& v)
{
	return Point (u.x() + v.x(), u.y() + v.y()); //don't creates local variable. The object without name 
}

Point& operator+=(Point& p1, const Point& p2)
{
	p1.x() += p2.x();
	p1.y() += p2.y();
	return p1;
}

bool operator==(const Point& u, const Point& v)
{
	if(u.x() != v.x()) return false;
	if(u.y() != v.y()) return false;
	return true;
}

bool operator!=(const Point& u, const Point& v)
{
	return !(u==v);
}

bool operator>=(const Point& u, const Point& v) 
{
	return u.x() >= v.x() && u.y() >= v.y();
}

bool operator<=(const Point& u, const Point& v)
{
   return u.x() <= v.x() && u.y()<=v.y();
}

bool operator>(const Point& u, const Point& v)
{
	return !(u <= v);
}

bool operator<(const Point& u, const Point& v)
{
	return !(u >= v);
}