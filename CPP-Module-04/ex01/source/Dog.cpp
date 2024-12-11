
#include "../include/Dog.hpp"

Dog::Dog(void)
{
	Animal::setType("Dog");
	_brain = new Brain();
	std::cout << "Dog Default Constructor Called" << std::endl;
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
		delete _brain;
		_brain = new Brain(*(other._brain));
	}
	return (*this);
}

Dog::~Dog(void)
{
	if (_brain != NULL)
		delete _brain;
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound(void) const { std::cout << "WOOF" << std::endl; }

Brain*	Dog::getBrain(void) const { return (_brain); }