
#ifndef	EASYFIND_HPP
#define	EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T>
int	find(T data, int value)
{
	typename T::iterator	res = std::find(data.begin(), data.end(), value);
	if (res != data.end())
		return (*res);
	throw std::runtime_error("No such value.");
}

#endif