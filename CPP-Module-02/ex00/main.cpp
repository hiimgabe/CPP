#include <iostream>
#include "fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

/*
	Default constructor called					= Fixed a;
	Copy constructor called 					= Fixed b( a );
	Copy assignment operator called // <-- This line may be missing depending on your implementation
	getRawBits member function called
	Default constructor called 					= Fixed c;
	Copy assignment operator called				= c = b;
	getRawBits member function called
	getRawBits member function called			= std::cout << a.getRawBits() << std::endl;
	0
	getRawBits member function called			= std::cout << b.getRawBits() << std::endl;
	0
	getRawBits member function called			= std::cout << c.getRawBits() << std::endl;
	0
	Destructor called							= return 0;
	Destructor called
	Destructor called
*/