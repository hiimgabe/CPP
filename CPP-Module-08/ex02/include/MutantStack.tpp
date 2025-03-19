
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

template<typename T, typename C>
typename C::reverse_iterator	MutantStack<T, C>::rbegin(void)
{
	return (this->c.rbegin());
}

template<typename T, typename C>
typename C::reverse_iterator	MutantStack<T, C>::rend(void)
{
	return (this->c.rend());
}

template<typename T, typename C>
typename C::const_iterator	MutantStack<T, C>::begin(void) const
{
	return (this->c.begin());
}

template<typename T, typename C>
typename C::const_iterator	MutantStack<T, C>::end(void) const
{
	return (this->c.end());
}

template<typename T, typename C>
typename C::const_reverse_iterator	MutantStack<T, C>::rbegin(void) const
{
	return (this->c.crbegin());
}

template<typename T, typename C>
typename C::const_reverse_iterator	MutantStack<T, C>::rend(void) const
{
	return (this->c.crend());
}