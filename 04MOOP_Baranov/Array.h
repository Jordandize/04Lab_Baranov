#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <string>
#include <iostream>
using namespace std;

template <class Elem>
class Array
{
private:
	Elem * _allocator;
	size_t _size;
    Array(const Array&);
	Array& operator=(const Array&);

public:
	class BadArray;
	explicit Array(const size_t n = 0);
	~Array();

	      Elem& operator[](const size_t);
    const Elem& operator[](const size_t) const;

	inline size_t size() const { return _size; }
};

template <class Elem>
Array<Elem>::Array(const size_t n):
_size(n), _allocator(new Elem[n])
{ }

template <class Elem>
Array<Elem>::~Array()
{
	delete [] _allocator;
	return;
}

template <typename Elem>
class Array<Elem>::BadArray 
{
private:
	const string _reason;
	const size_t _index;

public:
	BadArray(string reason = "", const size_t index = 0):
	_reason(reason), _index(index)
	{ }
	~BadArray() { }

	void diagnose() const 
	{ 
		cout << _reason << ' ' << _index << endl;
	}
};

template <class Elem>
ostream& operator<<(ostream&, const Array<Elem>&);

#endif //_ARRAY_H_