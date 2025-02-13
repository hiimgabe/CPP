
#include "MutantStack.hpp"

template<typename T, typename C>
MutantStack<T, C>::MutantStack(void)
{}

template<typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack &other)
{
	*this = other;
}

template<typename T, typename C>
MutantStack<T, C> &MutantStack<T, C>::operator=(const MutantStack &other)
{
	if (this != &other)
		std::stack<T, C>::operator=(other);
	return (*this);
}

template<typename T, typename C>
MutantStack<T, C>::~MutantStack(void)
{}

template<typename T, typename C>
typename C::iterator	MutantStack<T, C>::begin(void)
{
	return (this->c.begin());
}

template<typename T, typename C>
typename C::iterator	MutantStack<T, C>::end(void)
{
	return (this->c.end());
}