
#include "../include/BitcoinExchange.hpp"

Bitcoin::Bitcoin(void) { LOG("Bitcoin Default Constructor called."); }

Bitcoin::Bitcoin(const Bitcoin &rhs)
{
	LOG ("Bitcoin Copy Constructor called.");
	*this = rhs;
}

Bitcoin	&Bitcoin::operator=(const Bitcoin &rhs)
{
	(void)rhs;
	LOG("Bitcoin Assign Operator called.");
	return (*this);
}

Bitcoin::~Bitcoin(void)
{
	LOG("Bitcoin Destructor called.");
}