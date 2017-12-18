#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

//#define NDEBAG //output in consol just created/deleted triangle

#include <iostream>
#include "Point.h"
#include "Segment.h"
using namespace std;

class Point;
class Segment;

class Triangle
{

private:

	Point _a, _b, _c;
	mutable Segment *_ab, *_bc, *_ca;

public:

	Triangle(const double x1=0, const double y1=0,
			 const double x2=1, const double y2=0,
			 const double x3=0, const double y3=1):
	_a(x1, y1), _b(x2, y2), _c(x3, y3),
	_ab(0), _bc(0), _ca(0)
	{}

	Triangle(const Point &a, const Point& b, const Point& c):
	_a(a), _b(b), _c(c),
	_ab(0), _bc(0), _ca(0)
	{}

	Triangle(const Point &a, const Segment &bc):
	_a(a), 
	_b(bc.start()), _c(bc.end()),
	_ab(0), _bc(0), _ca(0)
	{}

	Triangle (const Triangle& tr):
	_a(tr._a), _b(tr._b), _c(tr._c),
	_ab(0), _bc(0), _ca(0)
	{}

	~Triangle()
	{
		if(_ab != 0) delete _ab;
		if(_bc != 0) delete _bc;
		if(_ca != 0) delete _ca;
	}

	Triangle& operator=(const Triangle& tr)
	{
		if(this == &tr) return *this;
		_a = tr._a;
		_b = tr._b;
		_c = tr._c;
		return *this;
	}

	double perimeter() const;
	double area() const;

	// Вершини
	const Point& apexA() const { return _a; }
	const Point& apexB() const { return _b; }
	const Point& apexC() const { return _c; }

	Point& apexA() { return _a; };
	Point& apexB() { return _b; };
	Point& apexC() { return _c; };

	// Сторони
	const Segment& side_a() const;
	const Segment& side_b() const;
	const Segment& side_c() const;

	// Довжини сторін
	double length_a() const;
	double length_b() const;
	double length_c() const;

	// Висоти
	const Segment height_a() const;
	const Segment height_b() const;
	const Segment height_c() const;

};

ostream& operator<<(ostream &, const Triangle &);

#endif