
#include "../include/AForm.hpp"

AForm::AForm(const std::string &name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	LOG("AForm Default Constructor called.");
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &other): _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	LOG("Bureacrat Copy Constructor called.");
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
		throw AForm::GradeTooLowSignException();
	else
	{
		this->_isSigned = true;
		std::cout << bureaucrat.getName() << " signed form: " << this->getName() << std::endl;
	}
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowExecuteException();
	if (!this->_isSigned)
		throw FormSignException();
	std::cout << "Executing form: " << this->_name << "\nBureaucrat: " << executor.getName() << std::endl;
	this->execute();
}


std::string AForm::getName(void) const{ return (_name); }

int	AForm::getSignGrade(void) const { return (_signGrade); }

int	AForm::getExecGrade(void) const { return (_execGrade); }

bool	AForm::getIsSigned(void) const { return (_isSigned); }

void AForm::setIsSigned(bool sign) { _isSigned = sign; }



std::ostream	&operator<<(std::ostream &os, const AForm &form)
{
	std::string	sign = form.getIsSigned() ? "True" : "False";

	os	<< "Form: " << form.getName()
		<< "\nSign Grade: "<< form.getSignGrade()
		<< "\nExec Grade: " << form.getExecGrade()
		<< "\nSigned: " << sign << std::endl;
	return (os);
}

const char	*AForm::GradeTooHighException::what(void) const throw() { return ("Grade is too high."); }

const char	*AForm::GradeTooLowException::what(void) const throw() { return ("Grade is too low."); }

const char	*AForm::GradeTooLowSignException::what(void) const throw() { return ("Can't sign, grade is too low."); }

const char	*AForm::GradeTooLowExecuteException::what(void) const throw() { return ("Can't execute, grade is too low."); }

const char	*AForm::FormSignException::what(void) const throw() { return ("Form isn't signed."); }