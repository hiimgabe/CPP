
#include "../include/Form.hpp"

Form::Form(std::string &name, int signGrade, int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
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
		<< "Signed: " << sign << std::endl;
	return (os);
}