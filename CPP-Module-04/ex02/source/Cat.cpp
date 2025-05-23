
#include "../include/Cat.hpp"

Cat::Cat(void)
{
	AAnimal::setType("Cat");
	_brain = new Brain();
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	*this = other;
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		_brain = new Brain(*(other._brain));
	}
	return (*this);
}

Cat::~Cat(void)
{
	if (_brain != NULL)
		delete _brain;
	std::cout << "Cat Default Destructor Called" << std::endl;
}

void	Cat::makeSound(void) const { std::cout << "Meow" << std::endl; }

Brain*	Cat::getBrain(void) const { return (_brain); }