#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <iostream>

#include "Array.h"
#include "Array.cpp"

template <class Elem>
class Deque
{
private:
	Array<Elem> * _allocator;

	size_t _size;
	size_t _front;
	size_t _back;
	size_t nextIndex(const size_t);
	size_t prevIndex(const size_t);

	void resize(size_t);
	void enlarge();
	void reduce();
	
	Deque(const Deque&);
	Deque& operator=(const Deque&);

public:
	class BadDeque;
	
	Deque(const size_t size = 0);
   ~Deque();
	
    inline bool empty() const { return _size == 0;          }
	inline bool full()  const { return _size == capacity(); }
	
	inline const Array<Elem> * allocator() const { return _allocator; }
	inline size_t capacity() const { return _allocator->size(); }
	inline size_t size()     const { return _size; }
	inline const Elem& front() const { return (*_allocator)[_front]; }
	inline const Elem& back()  const { return (*_allocator)[_back ]; }
	inline const size_t& frontI() const { return _front; }
	inline const size_t& backI () const { return _back ; }

	void putFront(const Elem&);
	void putBack (const Elem&);
	void popFront();
	void popBack ();
};

template <class Elem>
Deque<Elem>::Deque (const size_t size):
_size(0), _front(0), _back(-1),
_allocator(new Array<Elem>(size))
{ }

template <class Elem>
Deque<Elem>::~Deque()
{ 
	if(_allocator) delete _allocator;
}

template <class Elem>
ostream& operator<<(ostream&, Deque<Elem>&);

#endif