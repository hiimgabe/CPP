
#include "../include/AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") { std::cout << "Animal Default Constructor Called" << std::endl; }

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal Copy Constructor Called" << std::endl;
	*this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal Assign Operator Called" << std::endl;
	if (this != &other)
	{
		_type = other.getType();
	}
	return (*this);
}

AAnimal::~AAnimal() { std::cout << "AAnimal Destructor Called" << std::endl; }


std::string AAnimal::getType() const { return (_type); }

void	AAnimal::setType(const std::string &type) { _type = type; }
