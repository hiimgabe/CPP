
#include "../include/AForm.hpp"

AForm::AForm(void): _name("Default"), _signGrade(42), _execGrade(42), _isSigned(false) { LOG("AForm Default Constructor called."); }

AForm::AForm(const AForm &other): _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _isSigned(other._isSigned)
{
	LOG("AForm Copy Constructor called.");
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	LOG("AForm Assign Operator called.");
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm(void) { LOG("AForm Destructor called."); }


void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		std::cout << "Fix this" << std::endl;//throw AForm::GradeTooLowException();
	else
		this->_isSigned = true;
}

// Getters Setters

std::string AForm::getName(void) const { return (_name); }

int	AForm::getSignGrade(void) const { return (_signGrade); }

int	AForm::getExecGrade(void) const { return (_execGrade); }

bool	AForm::getIsSigned(void) const { return (_isSigned); }

void	AForm::setName(const std::string &name) { _name = name; }

void	AForm::setSignGrade(int signGrade) { _signGrade = signGrade; }

void	AForm::setExecGrade(int execGrade) { _execGrade = execGrade; }

void	AForm::setIsSigned(bool sign) { _isSigned = sign; }


// Operator Overloading

std::ostream	&operator<<(std::ostream &os, AForm &form)
{
	std::string	sign = form.getIsSigned() ? "True" : "False";

	os	<< "\nForm :" << form.getName()
		<< "\nSign Grade: " << form.getSignGrade()
		<< "\nExec Grade: " << form.getExecGrade()
		<< "\nSigned : " << sign
		<< std::endl;
	return (os);
}