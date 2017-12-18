#ifndef _CONVEX_H_
#define _CONVEX_H_

#define NBAG

#include "Point.h"
#include "Polygon.h"

class Convex
{
friend ostream& operator<<(ostream&, Convex&);
private:
	// �������������� ������� ����� � ��������:
	// �����, ����, �� ��� ����� ����
	enum Angles { zero, one, two, many };
	Angles _angles;
	// ����� �� ����� ��������
	Point _a, _b;
	// ����������� (������� ����� �������� ����� ����)
	Polygon * _pm;
	// �����
	double _area;
	// ��������
	double _peri;
	// �������� ����� �����
	void process0(const Point&);
	// �������� ����� �����
	void process1(const Point&);
	// �������� ����� �����
	void process2(const Point&);
	// �������� �������� ���� ������ �����
	void processN(const Point&);
public:
	Convex();
   ~Convex();
	// �������� ������� �����
	Convex& add(const Point&);
	// ������� �� ������� ����� � ��������
	// (����, �� ��� �����) ��������� �������� ���
	// ���������� �� ��������� ����������
	inline double perimeter() const { return _peri; }
	// �� � ���� � ������
	inline double area() const { return _area; }
};

ostream& operator<<(ostream&, Convex&);

#endif //_CONVEX_H_
