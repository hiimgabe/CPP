
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
		typedef typename C::reverse_iterator reverse_iterator;
		typedef typename C::const_iterator const_iterator;
		typedef typename C::const_reverse_iterator const_reverse_iterator;
		
		iterator	begin(void);
		iterator	end(void);
		
		reverse_iterator	rbegin(void);
		reverse_iterator	rend(void);

		const_iterator	cbegin(void);
		const_iterator	cend(void);

		const_reverse_iterator	crbegin(void);
		const_reverse_iterator	crend(void);
};

#include "MutantStack.tpp"

#endif