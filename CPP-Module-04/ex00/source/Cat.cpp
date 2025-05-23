
#include "../include/Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat Default Constructor Called" << std::endl;
	Animal::setType("Cat");
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat(void) { std::cout << "Cat Default Destructor Called" << std::endl; }

void	Cat::makeSound(void) const { std::cout << getType() << ": Meow" << std::endl; }

std::ostream &operator<<(std::ostream &ofs, const Cat &cat)
{
	std::cout << "\n=== Cat overload << operator ===" << std::endl;
	ofs << "Animal of type: " << cat.getType() << "\n";
	cat.makeSound();
	return (ofs);
}