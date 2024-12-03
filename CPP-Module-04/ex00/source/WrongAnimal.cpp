
#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("wrongAnimal") { std::cout << "WrongAnimal Default Constructor Called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal Default Cosntructor Called" << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		_type = other.getType();
	return (*this);		
}

WrongAnimal::~WrongAnimal(void) { std::cout << "WrongAnimal Destructor Called" << std::endl; }

std::string WrongAnimal::getType() const { return (_type); }

void	WrongAnimal::setType(std::string type) { _type = type; }

void	WrongAnimal::makeSound() const { std::cout << getType() << ": Hi!" << std::endl; }