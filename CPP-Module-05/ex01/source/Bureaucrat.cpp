
#include "../include/Bureaucrat.hpp"

// OCF

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
	LOG("Bureaucrat Default Constructor called.");
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	LOG("Bureacrat Copy Constructor called.");
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	LOG("Bureaucrat Assign Operator called.");
	if (this != &other)
	{
		this->_name = other.getName();
		this->_grade = other.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void) { LOG("Bureaucrat Destructor called."); }


// Member Functions

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (os);
}

// Getters

int	Bureaucrat::getGrade(void) const { return (_grade); }

std::string	Bureaucrat::getName(void) const { return (_name); }

void	Bureaucrat::promote(void)
{
	if (this->getGrade() == 1)
		throw Bureaucrat::PromotionException();
	this->_grade--;
}

void	Bureaucrat::demote(void)
{
	if (this->getGrade() == 150)
		throw Bureaucrat::DemotionException();
	this->_grade++;
}


// Exceptions

const char *Bureaucrat::GradeTooHighException::what(void) const throw() { return ("Grade is too high.");}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() { return ("Grade is too low.");}

const char *Bureaucrat::PromotionException::what(void) const throw() { return ("Bureaucrat's already at the highest grade.");}

const char *Bureaucrat::DemotionException::what(void) const throw() { return ("Bureaucrat's already at the lowest grade.");}
