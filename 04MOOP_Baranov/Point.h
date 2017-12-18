#ifndef _POINT_H_
#define _POINT_H_

//#define NDEBAG //output in consol ID and (x,y) of just created/deleted point

#include <iostream>
using namespace std;

class Point
{
private:
	static int freeID;
	const int pointID;
	double _x;
	double _y;
public:
	//overload of default constructor
	Point::Point(double x = 0, double y = 0):
	_x(x), _y(y), 
	pointID(freeID++)
	{
		#ifdef NDEBAG
		cout << "created Point (" << _x << "," << _y << ") ID = " << pointID << endl;
		#endif
	}

	//the constructor of copy
	Point::Point(const Point& p):
	_x(p._x), _y(p._y), 
	pointID(freeID++)
	{
		#ifdef NDEBAG
		cout << "created Point (" << _x << "," << _y << ") ID = " << pointID << endl;
		#endif
	}

	Point::~Point() 
	{
		#ifdef NDEBAG
		cout << "deleted Point (" << _x << "," << _y << ") ID = " << pointID << endl;
		#endif
	}

	//overload of default operator
	Point& Point::operator=(const Point& p)
	{
		if(this == &p) return *this;
		_x = p._x;
		_y = p._y;
		return *this;
	}

	//all this method is "inline", so we have some more faster program
	double& x() { return _x; }
	double& y() { return _y; }

	const double& x() const { return _x;	  }
	const double& y() const { return _y;	  }
	const int getID() const { return pointID; }
	static int amount()		{ return freeID;  }
};

ostream& operator<<(ostream&, const Point&);

const Point operator+(const Point & u, const Point & v);
Point& operator+=(Point &, const Point&);

bool operator==(const Point&, const Point&);
bool operator!=(const Point&, const Point&);
bool operator>=(const Point&, const Point&);
bool operator<=(const Point&, const Point&); 
bool operator> (const Point&, const Point&);
bool operator< (const Point&, const Point&); 

#endif