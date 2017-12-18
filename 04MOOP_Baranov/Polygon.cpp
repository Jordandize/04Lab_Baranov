#include "Polygon.h"
#include "Triangle.h"
#include <math.h>
#include <iostream>

Polygon::Polygon(const Point& p1,const Point& p2,const Point& p3):
_d(new Deque<Point>()), _edges(3)
{
	if(!(Segment(p1,p2).distance(p3) > 0))
		throw "Initial three points locate on the one line";

	Triangle t(p1, p2, p3);
	_area = t.area();
	_perimeter = t.perimeter();

	(*_d).putFront(p2);
	if(illuminated(Segment(p1,p3), p2))
	{
		(*_d).putFront(p1);
		(*_d).putBack(p3);
	}
	else
	{
		(*_d).putFront(p3);
		(*_d).putBack(p1);
	}
}

Polygon::~Polygon()
{
	if(_d != 0) delete _d;
}

void Polygon::process(const Point& t) 
{
	//edges counter
	size_t k = 0;

	//find first edge to delete
	while (k < _edges && !illuminated(Segment((*_d).back(), (*_d).front()), t))
	{
		//choose next edge
		(*_d).putBack((*_d).front());
		(*_d).popFront();
		k++;
	}

	//if new point locates inside polygon - terminate process
	
	if(k == _edges) return;

	//else delete finded illuminated edge
	delEdge(Segment((*_d).back(), (*_d).front()), t);
	//(*_d).popFront();
	//start verify oher illuminated edges from deque front
	//take start point of next maybe illuminated edge
	Point x0 = (*_d).front();
	//to the next point edge
	(*_d).popFront();
	//and delete all other illuminated edges while it is
	while(k < _edges && illuminated(Segment(x0, (*_d).front()), t))
	{
		//delete
		delEdge(Segment(x0, (*_d).front()), t);
		//remember last
		x0 = (*_d).front();
		//to the next point edge
		(*_d).popFront();
		k++;
	}
	//put back the start point of next maybe illuminated edge
	(*_d).putFront(x0);


	//start verify other illuminated edges from deque back
	//this block is the same as for deque front

	Point x1 = (*_d).back();
	(*_d).popBack();
	while(k < _edges && illuminated(Segment((*_d).back(), x1), t))
	{
		delEdge(Segment((*_d).back(), x1), t);
		x1 = (*_d).back();
		(*_d).popBack();
	}
	(*_d).putBack(x1);

	//add new edges
	_edges += 2;
	//add edges length to perimeter
	_perimeter += Segment((*_d).front(), t).length() + Segment((*_d).back(), t).length();
	//add new point to deque
	(*_d).putFront(t);
}

void Polygon::delEdge(const Segment& s, const Point& p)
{
	_edges--;
	_perimeter -= s.length();
	_area += Triangle(s.start(), s.end(), p).area();
}

bool Polygon::illuminated(const Segment& s, const Point& t) const
{
	double oa = oriTriangleArea(s, t);
	return oa < 0 || ((oa == 0) && (s.distance(t) > 0));
}

double Polygon::oriTriangleArea(const Segment& s, const Point& t) const
{
	return ((s.startX() - t.x())*(s.endY() - t.y()) - (s.startY() - t.y())*(s.endX() - t.x()))*0.5;
}

bool Polygon::onLine(const Segment& s, const Point& p) const
{
	if(s.distance(p) <= 0)
	{
		if(p >= s.start() && p <= s.end())
			return true;
	}
	return false;
}

ostream& operator<<(ostream& os, Polygon& p) 
{
	os << "Peri: " << p.perimeter() << endl;
	os << "Area: " << p.area() << endl;
	os << *(p.points());
	os << endl;
	return os;
}