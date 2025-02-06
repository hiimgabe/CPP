
#ifndef	BASE_HPP
#define	BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

/*
*	dynamic_cast
*	used for safe casting in classes hierarchies
*	works only with polymorphic classes
*/

class Base
{
	public:
		virtual ~Base(void);
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif