#ifndef _CONVEX_H_
#define _CONVEX_H_

#define NBAG

#include "Point.h"
#include "Polygon.h"

class Convex
{
friend ostream& operator<<(ostream&, Convex&);
private:
	// Характеристика кількості точок в оболонці:
	// жодної, одна, дві або більше двох
	enum Angles { zero, one, two, many };
	Angles _angles;
	// Перші дві точки оболонки
	Point _a, _b;
	// Многокутник (кількість точок оболонки більша двох)
	Polygon * _pm;
	// Площа
	double _area;
	// Периметр
	double _peri;
	// Обробити першу точку
	void process0(const Point&);
	// Обробити другу точку
	void process1(const Point&);
	// Обробити третю точку
	void process2(const Point&);
	// Обробити наступну після третьої точки
	void processN(const Point&);
public:
	Convex();
   ~Convex();
	// Долучити чергову точку
	Convex& add(const Point&);
	// Залежно від кількості точок в оболонці
	// (одна, дві або більше) обчислити периметр або
	// звернутися до периметра многутника
	inline double perimeter() const { return _peri; }
	// Те ж саме з площею
	inline double area() const { return _area; }
};

ostream& operator<<(ostream&, Convex&);

#endif //_CONVEX_H_
