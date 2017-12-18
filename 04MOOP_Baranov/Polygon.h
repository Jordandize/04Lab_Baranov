#ifndef _POLYGON_H_
#define _POLYGON_H_

#include "Deque.h"
#include "Deque.cpp"
#include "Point.h"
#include "Segment.h"

class Polygon
{
public:
   // ������� �� ������������ ����� ��� �����
   Polygon(const Point&,const Point&,const Point&);
   ~Polygon();
   // �������� ����� �� ������������
   void process(const Point&);
   // ��������� � ���������� ��������
   double perimeter() const {return _perimeter;}
   // ��������� � ���������� �����
   double area() const {return _area;}
   //��������� �����
   inline Deque<Point>* points() {return _d;}

private:
   // ������� ������ ��������, �������� � ����������� ����
   Deque<Point>* _d;
   // ʳ������ ������ � ������ ��������
   size_t _edges;
   // �������� ���������
   double _perimeter;
   // �������� �����
   double _area;
   // ���������, �� ����������� ����� a�� ��������s
   bool illuminated(const Segment&, const Point&) const;
   // ������� ������� s����� ������ ���������,
   // ������ ������� s� ������ a
   void delEdge(const Segment&, const Point&);
   //�����
   double oriTriangleArea(const Segment&, const Point&) const;
   //on line
   bool onLine(const Segment&, const Point&) const;
};

ostream& operator<<(ostream &, Polygon &);

#endif