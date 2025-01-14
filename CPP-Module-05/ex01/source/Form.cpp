
#include "../include/Form.hpp"

Form::Form(std::string &name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	LOG("Form Default Constructor called.");
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &other): _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	LOG("Bureacrat Copy Constructor called.");
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	LOG("Form Assign Operator called.");
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

Form::~Form(void) { LOG("Form Destructor called."); }


void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
}


std::string Form::getName(void) const{ return (_name); }

int	Form::getSignGrade(void) const { return (_signGrade); }

int	Form::getExecGrade(void) const { return (_execGrade); }

bool	Form::getIsSigned(void) const { return (_isSigned); }


std::ostream &operator<<(std::ostream &os, const Form &form)
{
	std::string	sign = form.getIsSigned() ? "True" : "False";
	os	<< "Form: " << form.getName()
		<< "\nSign Grade: "<< form.getSignGrade()
		<< "\nExec Grade: " << form.getExecGrade()
		<< "\nSigned: " << sign << std::endl;
	return (os);
}

const char	*Form::GradeTooHighException::what(void) const throw() { return ("Grade is too high."); }

const char	*Form::GradeTooLowException::what(void) const throw() { return ("Grade is too low."); }