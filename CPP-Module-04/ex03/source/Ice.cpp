
#include "../include/Ice.hpp"

Ice::Ice(void)
{
	std::cout << "Ice default constructor called." << std::endl;
	_type = "ice";
	_inUse = false;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Ice copy constructor called." << std::endl;
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << "Ice assign operator called." << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Ice::~Ice(void) { std::cout << "Ice destructor called." << std::endl; }



AMateria* Ice::clone(void) const { return (new Ice(*this)); }

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}