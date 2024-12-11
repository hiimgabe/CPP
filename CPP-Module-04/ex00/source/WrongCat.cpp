
#include "../include/WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat Default Constructor Called" << std::endl;
	WrongAnimal::setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat Copy Constructor Called" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat(void) { std::cout << "WrongCat Destructor Called" << std::endl; }

void WrongCat::makeSound() const { std::cout << getType() << ": MooOOoOoOoOOOoOOO" << std::endl; }

std::ostream &operator<<(std::ostream &ofs, const WrongCat &wrongCat)
{
	std::cout << "\n=== WrongCat overload << operator ===" << std::endl;
	ofs << "Animal of type: " << wrongCat.getType() << "\n";
	wrongCat.makeSound();
	return (ofs);
}
