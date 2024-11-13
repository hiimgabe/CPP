
#include "../include/Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog Default Constructor Called" << std::endl;
	Animal::setType("Dog");
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog(void) { std::cout << "Dog Destructor called" << std::endl; }

void Dog::makeSound(void) const { std::cout << "WOOF" << std::endl; }