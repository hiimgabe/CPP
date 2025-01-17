
#include "../include/Intern.hpp"

Intern::Intern(void) { LOG("Intern Default Constructor called."); }

Intern::Intern(const Intern &other)
{
	LOG("Intern Copy Constructor called");
	*this = other;
}

Intern	&Intern::operator=(const Intern &other)
{
	LOG("Intern Assign Operator Constructor called.");
	if (this == &other)
		std::cout << "Object is the same." << std::endl;
	(void)other;
	return (*this);
}

Intern::~Intern(void) { LOG("Intern Destructor called."); }

AForm*	Intern::makeForm(const std::string &formName, const std::string &target) const
{
	AForm*	(Intern::*formArray[3])(const std::string &) const =
	{
		&Intern::makeShrubberyForm,
		&Intern::makeRobotomyForm,
		&Intern::makePresidentialForm
	};
	std::string	forms[3] =
	{
		"shrubbery form",
		"robotomy form",
		"presidential form",
	};
	for (int i = 0; i < 3; i++)
		if (forms[i] == formName)
			return((this->*formArray[i])(target));
	throw Intern::internFormException();
}

AForm*	Intern::makeShrubberyForm(const std::string &target) const { return (new ShrubberyCreationForm(target)); }

AForm*	Intern::makeRobotomyForm(const std::string &target) const { return (new RobotomyRequestForm(target)); }

AForm*	Intern::makePresidentialForm(const std::string &target) const { return (new PresidentialPardonForm(target)); }

const char	*Intern::internFormException::what(void) const throw() { return ("No such form."); }