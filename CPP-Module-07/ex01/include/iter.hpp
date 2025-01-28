
#ifndef	ITER_hpp
#define	ITER_hpp

#include <iostream>

template	<typename A, typename F>
void	iter(A *array, size_t l, F f)
{
	for (size_t i = 0; i < l; i++)
		f(array[i]);
}

#endif