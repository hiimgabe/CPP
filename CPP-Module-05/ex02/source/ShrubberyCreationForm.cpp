
#include "../include/ShrubberyCreationForm.hpp"

Shrubbery::Shrubbery(const std::string &target): AForm("Shrubbery", 145, 137), _target(target) { LOG("Shrubbery Default Constructor called."); }

Shrubbery::Shrubbery(const Shrubbery &other): AForm(other)
{
	LOG("Shrubbery Copy Constructor called.");
	*this = other;
}

Shrubbery &Shrubbery::operator=(const Shrubbery &other)
{
	LOG("Shrubbery Assign Operator called.");
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

Shrubbery::~Shrubbery(void) { LOG("Shrubbery Destructor called."); }


// Member Functions

void	Shrubbery::execute(void) const
{
	std::ofstream	file;
	std::string		shrubberyName = _target + "_Shrubbery";

	file.open(shrubberyName.c_str());
	file << TREE;
	file.close();
	std::cout << shrubberyName + "_Shrubbery created succesfully" << std::endl;
}
