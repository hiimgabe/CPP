
#ifndef	MUTANTSTACK_HPP
#define	MUTANTSTACK_HPP

#ifdef DEBUG
#define LOG(str)	std::cout << str << std::endl;
#else
#define LOG(str)
#endif

#include <iostream>
#include <stack>

template <typename T, typename C = std::deque<T>>
class MutantStack : public std::stack<T>
{
};

#endif