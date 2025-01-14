
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