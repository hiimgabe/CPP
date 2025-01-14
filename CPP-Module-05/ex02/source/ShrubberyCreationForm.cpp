
#include "../include/ShrubberyCreationForm.hpp"

Shrubbery::Shrubbery(const std::string &target): _name("Shrubbery"), _signGrade(145), _execGrade(137), _isSigned(false)
{
	LOG("Shrubbery Default Constructor called.");
	// Continue here
	// Creates a file <target>_Shrubbery with ASCII trees inside
}

Shrubbery::Shrubbery(const Shrubbery &other): _name(other._name), _signGrade(145), _execGrade(137), _isSigned(other._isSigned)
{
	LOG("Shrubbery Copy Constructor called.");
	*this = other;
}

Shrubbery &Shrubbery::operator=(const Shrubbery &other)
{
	LOG("Shrubbery Assign Operator called.");
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}
