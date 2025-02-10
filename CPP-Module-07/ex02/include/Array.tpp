
#include "Array.hpp"

template <class T> Array<T>::Array(void)
{
	LOG("Array Default Constructor called.");
	this->_array = new T[0];
	this->_size = 0;
}

template <class T> Array<T>::Array(unsigned int n)
{
	LOG("Array unsigned int Constructor called.");
	this->_array = new T[n];
	this->_size = n;
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = 0;
}

template <class T> Array<T>::Array(const Array &other): _array(other._array), _size(other._size)
{
	LOG("Array Copy Constructor called.");
	*this = other;
}

template <class T> Array<T> &Array<T>::operator=(const Array &other)
{
	LOG("Array Assign Operator called.");
	if (this != &other)
	{
		delete[] (this->_array);
		this->_array = new T[other._size];
		this->_size = other._size;
		for (unsigned int i = 0; i < other._size; i++)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

template <class T> T &Array<T>::operator[](unsigned int n)
{
	if (n >= this->_size)
		throw outOfBoundsException();
	return (this->_array[n]);
}

template <class T> unsigned int Array<T>::size(void) const { return (this->_size); }

template <class T> Array<T>::~Array(void)
{
	LOG("Array Desctructor called.");
	delete[] (this->_array);
}

template <class T> const char	*Array<T>::outOfBoundsException::what() const throw()
{
	return ("Out of bounds.");
}


template <class T> const char	*Array<T>::invalidSizeException::what() const throw()
{
	return ("Invalid size n.");
}