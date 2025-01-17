
#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	LOG("PresidentialPardonForm Default constructor called.");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	LOG("PresidentialPardonForm Copy constructor called.");
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	LOG("PresidentialPardonForm Assign Operator called.");
	if (this != &other)
	{
		_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	LOG("PresidentialPardonForm Destructor called.");
}

void	PresidentialPardonForm::execute(void) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}