#ifndef _POLYGON_H_
#define _POLYGON_H_

#include "Deque.h"
#include "Deque.cpp"
#include "Point.h"
#include "Segment.h"

class Polygon
{
public:
   // Занести до многокутника перші три точки
   Polygon(const Point&,const Point&,const Point&);
   ~Polygon();
   // Долучити точку до многокутника
   void process(const Point&);
   // Обчислити і запам’ятати периметр
   double perimeter() const {return _perimeter;}
   // Обчислити і запам’ятати площу
   double area() const {return _area;}
   //Повернути точки
   inline Deque<Point>* points() {return _d;}

private:
   // Вершини опуклої оболонки, збережені в двосторонній черзі
   Deque<Point>* _d;
   // Кількість вершин в опуклій оболонці
   size_t _edges;
   // Значення периметру
   double _perimeter;
   // Значення площі
   double _area;
   // Перевірити, чи знаходиться точка aза стороноюs
   bool illuminated(const Segment&, const Point&) const;
   // Замінити сторону sдвома новими сторонами,
   // кінцями сторони sі точкою a
   void delEdge(const Segment&, const Point&);
   //Площа
   double oriTriangleArea(const Segment&, const Point&) const;
   //on line
   bool onLine(const Segment&, const Point&) const;
};

ostream& operator<<(ostream &, Polygon &);

#endif