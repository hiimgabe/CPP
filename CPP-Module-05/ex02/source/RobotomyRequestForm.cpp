
#include "../include/RobotomyRequestForm.hpp"
#include <unistd.h>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("Shrubbery", 72, 45), _target(target) { LOG("RobotomyRequestForm Default Constructor called."); }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other)
{
	LOG("RobotomyRequestForm Copy Constructor called.");
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	LOG("RobotomyRequestForm Assign Operator called.");
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) { LOG("RobotomyRequestForm Destructor called."); }


// Member Functions

void	RobotomyRequestForm::execute(void) const
{
	std::cout << "*Drilling noises*" << std::endl;

	usleep(500000);

	if (std::rand() % 2 == 0)
		return (std::cout << _target << " has been Robotomized Successfully :D" << std::endl, void());
	std::cout << "Coudln't Robotomize " << _target << " :(" << std::endl;
}
