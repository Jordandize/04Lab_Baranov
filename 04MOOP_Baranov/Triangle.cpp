#include "Triangle.h"
#include "Segment.h"
#include <iostream>
using namespace std;

// Сторони
const Segment& Triangle::side_a() const
{
	if(_bc == 0)
		_bc = new Segment(_b, _c);
	return *_bc;
}

const Segment& Triangle::side_b() const
{
	if(_ca == 0)
		_ca = new Segment(_c, _a);
	return *_ca;
}

const Segment& Triangle::side_c() const
{
	if(_ab == 0)
		_ab = new Segment(_a, _b);
	return *_ab;
}

// Довжини сторін
double Triangle::length_a() const
{
	return side_a().length();
}

double Triangle::length_b() const
{
	return side_b().length();
}

double Triangle::length_c() const
{
	return side_c().length();
}

// Висоти
const Segment Triangle::height_a() const
{
	return Segment(side_a().middle(), apexA());
}

const Segment Triangle::height_b() const
{
	return Segment(side_b().middle(), apexB());
}

const Segment Triangle::height_c() const
{
	return Segment(side_c().middle(), apexC());
}

//Периметер
double Triangle::perimeter() const
{
	return side_a().length() + 
		   side_b().length() + 
		   side_c().length();
}

//Площа
double Triangle::area() const
{
	return 0.5*side_a().length()*side_a().distance(_a);
}


ostream& operator<<(ostream& os, const Triangle& tr)
{
	os 	<< "Triangle "
		<< tr.apexA()
		<< tr.apexB()
		<< tr.apexC()
		<< endl
		<< "perimeter: " << tr.perimeter() << endl
		<< "square:    " << tr.area()      << endl;
	return os;
}