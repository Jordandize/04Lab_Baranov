#include "Array.h"

template <class Elem>
Elem& Array<Elem>::operator[](const size_t index)
{
	if(_size <= index)
		throw BadArray("Illegal index: ", index);
	return *(_allocator + index);
}

template <class Elem>
const Elem& Array<Elem>::operator[](const size_t index) const
{
	if(_size <= index)
		throw BadArray("Illegal index: ", index);
	return *(_allocator + index);
}

template <class Elem>
ostream& operator<<(ostream& os, const Array<Elem>& a)
{
	for(size_t i = 0; i < a.size(); ++i)
		os << a[i] << endl;
	return os;   
}