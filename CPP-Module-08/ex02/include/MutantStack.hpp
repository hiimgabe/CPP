
#ifndef	MUTANTSTACK_HPP
#define	MUTANTSTACK_HPP

#include <iostream>
#include <stack>


/*
	template declaration

	T will hold data type
	C container will be a std::deque of type <T> by default
*/
template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack(void);
/*
	alias for the iterator type of the container C

	simplifies the code for reading and implementation reasons

	therefore begin() and end() will return C::iterator
*/
		typedef typename C::iterator iterator;
		iterator	begin(void);
		iterator	end(void);
};

#include "MutantStack.tpp"

#endif