
#ifndef	INTERN_H
#define	INTERN_H

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern(void);

		AForm*	makeForm(const std::string &formName, const std::string &target) const;
		AForm*	makeShrubberyForm(const std::string &target) const;
		AForm*	makeRobotomyForm(const std::string &target) const;
		AForm*	makePresidentialForm(const std::string &target) const;

		class	internFormException : std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

#endif