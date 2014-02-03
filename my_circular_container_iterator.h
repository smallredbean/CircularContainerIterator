#ifndef __MY_CIRCULAR_CONTAINER_ITERATOR_H__
#define __MY_CIRCULAR_CONTAINER_ITERATOR_H__

/* NOTE! When the container size is 0, the behavior is not guranteed.
 * It may run into infinite loop.
 */
template <class Container, class Iterator>
class MyCircularContainerIterator: public Iterator {
private:
	const Container *c;

public:
	MyCircularContainerIterator(const Container &_c, const Iterator _it)
		: Iterator(_it), c(&_c)
	{
	}

	MyCircularContainerIterator &operator=(const MyCircularContainerIterator &cit)
	{
		if (this == &cit) {  // check for self-assignment
			return *this;
		}

		Iterator &tmp(*this);
		tmp = Iterator(cit);
		this->c = cit.c;
		return *this;
	}

	MyCircularContainerIterator &operator+=(int delta)
	{
		Iterator &tmp(*this);
		tmp += delta;

		while (tmp < c->cbegin()) {
			tmp += c->size();
		}
		while (tmp >= c->cend()) {
			tmp -= c->size();
		}
		return *this;
	}

	MyCircularContainerIterator &operator-=(int delta)
	{
		return operator+=(-delta);
	}

	MyCircularContainerIterator &operator++()  // ++i
	{
		return operator+=(1);
	}

	const MyCircularContainerIterator operator++(int)  // i++
	{
		MyCircularContainerIterator tmp(*this);
		operator++();
		return tmp;
	}

	MyCircularContainerIterator &operator--()  // --i
	{
		return operator-=(1);
	}

	const MyCircularContainerIterator operator--(int)  // i--
	{
		MyCircularContainerIterator tmp(*this);
		operator--();
		return tmp;
	}

	const MyCircularContainerIterator operator+(int delta) const
	{
		return MyCircularContainerIterator(*this) += delta;
	}

	const MyCircularContainerIterator operator-(int delta) const
	{
		return operator+(-delta);
	}

	// The index returned only works for Container that supports random access
	const typename Container::size_type iterator2index(void) const
	{
		const Iterator &tmp(*this);
		return tmp - c->cbegin();
	}
};
#endif
