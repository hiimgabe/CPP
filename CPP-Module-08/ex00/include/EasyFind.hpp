
#ifndef	EASYFIND_HPP
#define	EASYFIND_HPP

#include <algorithm>
#include <iostream>

class	NoSuchValue : public std::exception
{
	public:
		const char *what() const throw() { return ("Number not found."); }
};

template <typename T>
int	find(T data, int value)
{
	typename T::iterator	res = std::find(data.begin(), data.end(), value);
	if (res != data.end())
		return (std::distance(data.begin(), res));
	throw NoSuchValue();
}

#endif