
#include "../include/Animal.hpp"

Animal::Animal() : _type("Animal") { std::cout << "Animal Default Constructor Called" << std::endl; }

Animal::Animal(const Animal &other)
{
	std::cout << "Animal Copy Constructor Called" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal Assign Operator Called" << std::endl;
	if (this != &other)
	{
		_type = other.getType();
	}
	return (*this);
}

Animal::~Animal() { std::cout << "Animal Destructor Called" << std::endl; }


std::string Animal::getType() const { return (_type); }

void	Animal::setType(const std::string &type) { _type = type; }


void Animal::makeSound() const { return ; }