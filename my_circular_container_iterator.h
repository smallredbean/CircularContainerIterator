#ifndef __MY_CIRCULAR_CONTAINER_ITERATOR_H__
#define __MY_CIRCULAR_CONTAINER_ITERATOR_H__

#include "my_circular_container_iterator.h"

template <class Container, class Iterator>
class MyCircularContainerIterator: public Iterator{
private:
	Container &c;

public:
	MyCircularContainerIterator(Container &_c, Iterator _it)
		: c(_c), Iterator(_it)
	{
	}

	MyCircularContainerIterator &operator++() // ++i
	{
		return this->operator+=(1);
	}

	MyCircularContainerIterator operator++(int) // i++
	{
		MyCircularContainerIterator tmp(*this);
		++(*this);
		return tmp;
	}

	MyCircularContainerIterator &operator--() // --i
	{
		return this->operator-=(1);
	}

	MyCircularContainerIterator operator--(int) // i--
	{
		MyCircularContainerIterator tmp(*this);
		--(*this);
		return tmp;
	}

	MyCircularContainerIterator operator+(int delta)
	{
		Iterator tmp(*this);
		tmp += delta;

		while(tmp<c.begin())
			tmp += c.size();
		while(tmp>=c.end())
			tmp -= c.size();

		return MyCircularContainerIterator(c, tmp);
	}

	MyCircularContainerIterator operator-(int delta)
	{
		return operator+(-delta);
	}

	MyCircularContainerIterator &operator+=(int delta)
	{
		*this = this->operator+(delta);
		return *this;
	}

	MyCircularContainerIterator &operator-=(int delta)
	{
		return operator+=(-delta);
	}

	MyCircularContainerIterator &operator=(const MyCircularContainerIterator &cit)
	{
		Iterator &tmp(*this);
		tmp = Iterator(cit);
		this->c = cit.c;
		return *this;
	}
};
#endif
