
#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("Shrubbery", 145, 137), _target(target) { LOG("ShrubberyCreationForm Default Constructor called."); }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other)
{
	LOG("ShrubberyCreationForm Copy Constructor called.");
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	LOG("ShrubberyCreationForm Assign Operator called.");
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) { LOG("ShrubberyCreationForm Destructor called."); }


// Member Functions

void	ShrubberyCreationForm::execute(void) const
{
	std::ofstream	file;
	std::string		shrubberyName = _target + "_Shrubbery";

	file.open(shrubberyName.c_str());
	file << TREE;
	file.close();
	std::cout << shrubberyName + "_Shrubbery created succesfully" << std::endl;
}
