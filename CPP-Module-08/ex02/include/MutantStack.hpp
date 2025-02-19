
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

		typedef typename C::iterator iterator;
		iterator	begin(void);
		iterator	end(void);
};

#include "MutantStack.tpp"

#endif