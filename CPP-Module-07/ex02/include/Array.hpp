
#ifndef	ARRAY_HPP
#define	ARRAY_HPP

#include <iostream>
#include <cstring>

#ifdef DEBUG
#define LOG(str) std::cout << str << std::endl;
#else
#define LOG(str)
#endif

template <class T> class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &other);
		Array	&operator=(const Array &other);
		~Array(void);

		unsigned int	size(void) const;
		T	&operator[](unsigned int n);

		class outOfBoundsException : public std::exception
		{
			const char *what(void) const throw();
		};

		class invalidSizeException : public std::exception
		{
			const char *what(void) const throw();
		};

	private:
		T				*_array;
		unsigned int	_size;
};

#include "Array.tpp"

#endif