
#ifndef	WHATEVER_HPP
#define	WHATEVER_HPP

#include <iostream>

template	<typename T>
void	swap(T &a, T &b)
{
	std::cout << "\nbefore\na: " << a << "\nb: " << b << std::endl;
	T	tmp = a;
	a = b;
	b = tmp;
	std::cout << "after\na: " << a << "\nb: " << b << "\n" << std::endl;
}

template	<typename T>
T	max(T a, T b) { return (a > b ? a : b); }

template	<typename T>
T	min(T a, T b) { return (a < b ? a : b); }

#endif