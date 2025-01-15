
#include "../include/ShrubberyCreationForm.hpp"

Shrubbery::Shrubbery(const std::string &target)
{
	LOG("Shrubbery Default Constructor called.");
	AForm::setName("Shrubbery Form");
	AForm::setSignGrade(145);
	AForm::setExecGrade(137);
	AForm::setIsSigned(false);
	std::cout << "Creating <" << target << ">_Shrubbery." << std::endl;
	// Continue here
	// Creates a file <target>_Shrubbery with ASCII trees inside
}

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
		AForm::setName(other.getName());
		AForm::setSignGrade(other.getSignGrade());
		AForm::setExecGrade(other.getExecGrade());
		AForm::setIsSigned(other.getIsSigned());
	}
	return (*this);
}

Shrubbery::~Shrubbery(void) { LOG("Shrubbery Destructor called."); }
