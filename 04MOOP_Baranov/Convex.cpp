#include "Convex.h"
#include "Segment.h"
#include <ostream>

Convex::Convex()
:_angles(zero)
{

}

Convex::~Convex()
{
	if(_pm != 0) delete _pm;
}

Convex& Convex::add(const Point& p) 
{
	#ifdef NBAG
		cout << "<add Point" << p << '>' << endl;
	#endif
    switch (_angles)
	{ 
        case zero:  
			process0(p); break; 
        case one: 
            process1(p); break; 
		case two:
			process2(p); break;
		case many:
			processN(p); break;
    } 
	return *this;
}

void Convex::process0(const Point& p)
{ 
	_a      = p;
	_peri   = 0;
	_area   = 0;
	_angles = one;
}

void Convex::process1(const Point& p) 
{
	if (p != _a)
	{
		_b      = p;
		_peri   = Segment(_a, _b).length();
		_area   = 0;
		_angles = two;
	}
}

void Convex::process2(const Point& p) 
{
	Segment s(_a, _b);
	if(s.distance(p) <= 0)
	{
		if(_a >= _b)
		{
			if(p <= _b)
			{
				_b = p;
			}
			else if(p >= _a)
			{
				_a = p;
			}
		}
		else
		{
			if(p <= _a)
			{
				_a = p;
			}
			else if(p >= _b)
			{
				_b = p;
			}
		}
	}
	else
	{
		_pm     = new Polygon(_a, p, _b);
		_peri   = (*_pm).perimeter();
		_area   = (*_pm).area();
		_angles = many;
	}
}

void Convex::processN(const Point& p) 
{
	(*_pm).process(p);
	_peri = (*_pm).perimeter();
	_area = (*_pm).area();
}

ostream& operator<<(ostream& os, Convex& c)
{
	switch(c._angles)
	{ 
		case c.zero:  
			os << "Null";
			break; 
        case c.one: 
            os << c._a;
            break; 
		case c.two:
			os << "{ " << c._a << " " << c._b << " }" << endl;
			os << "Peri: " << Segment(c._a, c._b).length();
			break;
		case c.many:
			os << (*c._pm);
			break;
    }
	return os;
}