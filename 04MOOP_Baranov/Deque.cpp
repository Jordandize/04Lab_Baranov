#include "Deque.h"

template <class Elem>
void Deque<Elem>::putFront(const Elem& val)
{
	if(full()) enlarge();
	_size++;
	_front = prevIndex(_front);
	(*_allocator)[_front] = val;
}

template <class Elem>
void Deque<Elem>::putBack(const Elem& val)
{
	if(full()) enlarge();
	_size++;
	_back = nextIndex(_back);
	(*_allocator)[_back] = val;
}

template <class Elem>
void Deque<Elem>::popFront()
{
	if(!_size) throw "Deque is empty";
	_size--;
	_front = nextIndex(_front);
}

template <class Elem>
void Deque<Elem>::popBack()
{
	if(!_size) throw "Deque is empty";
	_size--;
	_back = prevIndex(_back);
}

template <class Elem>
size_t Deque<Elem>::nextIndex(const size_t i)
{
	return (i < (capacity() - 1)) ? i + 1 : 0;
}

template <class Elem>
size_t Deque<Elem>::prevIndex(const size_t i)
{
	return !i ? capacity() - 1 : i - 1;
}

template <class Elem>
void Deque<Elem>::enlarge()
{
	size_t ncapacity = capacity() * 3 / 2 + 2;
	Array<Elem> * nallocator = new Array<Elem>(ncapacity);

	for(size_t i = frontI(), counter = 0; counter < size(); counter++, i = (i + 1) % capacity())
	{
		(*nallocator)[counter] = (*_allocator)[i];
	}
	_front = 0;
	_back  = size() - 1;

	delete _allocator;
	       _allocator = nallocator;
}

template <class Elem>
ostream& operator<<(ostream& os, Deque<Elem>& de)
{
	const Array<Elem> * alloc = de.allocator();
	os << "[ ";
	for(size_t i = de.frontI(), counter = 0; counter < de.size(); counter++, i = (i + 1) % de.capacity())
	{
		os << (*alloc)[i] << ' ';
	}
	os << ']';
	return os;
}