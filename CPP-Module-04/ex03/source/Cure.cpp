
#include "../include/Cure.hpp"

Cure::Cure(void)
{
	std::cout << "Cure default constructor called" << std::endl;
	_type = "cure";
	_inUse = false;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "Cure copy constructor called." << std::endl;
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Cure assign operator called." << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Cure::~Cure(void) { std::cout << "Cure destructor called." << std::endl; }



AMateria* Cure::clone(void) const { return (new Cure(*this)); }

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}