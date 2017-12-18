#ifndef _SEGMENT_H_
#define _SEGMENT_H_

//#define NDEBAG //output in consol ID and (P1,P2) of just created/deleted segment

#include <iostream>
#include "Point.h"
using namespace std;

class Segment
{
private:
	static int _freeID;
	const int _myID;
	const Point &_a, &_b;
	mutable Point * _middle;

public:

	Segment(const Point& start, const Point& end):
	_a(start), _b(end), _middle(0),
	_myID(_freeID++)
	{
		#ifdef NDEBAG
		cout << "created Segment (" << _a << "," << _b << ") ID = " << _myID << endl;
		#endif
	}

	//constructor of copy
	Segment(const Segment& that):
	_a(that._a), _b(that._b), _middle(0),
	_myID(_freeID++)
	{
		#ifdef NDEBAG
		cout << "created Segment (" << _a << "," << _b << ") ID = " << _myID << endl;
		#endif
	}

	~Segment()
	{
		if(_middle != 0) delete _middle;
		#ifdef NDEBAG
		cout << "deleted Segment (" << _a << "," << _b << ") ID = " << _myID << endl;
		#endif
	}

	//all this method is "inline", so we have some more faster program
	const Point& start()  const { return _a; }
	const Point& end()    const { return _b; }
	const Point& middle() const;

	const double &Segment::startX() const { return _a.x(); }
	const double &Segment::startY() const { return _a.y(); }
	const double &Segment::endX()   const { return _b.x(); }
	const double &Segment::endY()   const { return _b.y(); }

	double length () const;
	double distance (const Point&) const;

	const int getID() const { return _myID;  }
	static int amount() { return _freeID; }
};

ostream& operator<<(ostream &, const Segment &);

#endif