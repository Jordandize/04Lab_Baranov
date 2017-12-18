#include <iostream>
using namespace std;

#include "Point.h"
#include "Convex.h"
#include "Segment.h"
#include "Triangle.h"

int main() {
	Convex c;

	cout << endl << "Initial Convex State" << endl;
	cout << c << endl;

	cout << endl << "Add Point 1" << endl;
	c.add(Point(1,2));
	cout << c << endl;
	
	cout << endl << "#Add The Same Point" << endl;
	c.add(Point(1,2));
	cout << c << endl;

	cout << endl << "Add Point 2.1" << endl;
	c.add(Point(1,4));
	cout << c << endl;

	cout << endl << "#Add Point Beetween" << endl;
	c.add(Point(1,3));
	cout << c << endl;

	cout << endl << "Add Point 2.2" << endl;
	c.add(Point(1,5));
	cout << c << endl;

	cout << endl << "Add Point 2.3" << endl;
	c.add(Point(1,1));
	cout << c << endl;

	cout << endl << "Add Point 3" << endl;
	c.add(Point(5,1));
	cout << c << endl;

	cout << endl << "#Add Inside Point" << endl;
	c.add(Point(2,2));
	cout << c << endl;

	cout << endl << "Add Point 4" << endl;
	c.add(Point(5,5));
	cout << c << endl;
	
	cout << endl << "#Add Point on the edge" << endl;
	c.add(Point(1,3));
	cout << c << endl;

	cout << endl << "#Add Point Inside" << endl;
	c.add(Point(3,3));
	cout << c << endl;

	cout << endl << "Add Point 5" << endl;
	c.add(Point(1,11));
	cout << c << endl;

	cout << endl << "Add Point 6" << endl;
	c.add(Point(5,11));
	cout << c << endl;

	cout << endl << "#Add Point On The Edge" << endl;
	c.add(Point(1,3));
	cout << c << endl;

	return 0;
}