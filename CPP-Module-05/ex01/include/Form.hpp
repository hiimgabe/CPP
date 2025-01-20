
#ifndef	FORM_H
#define	FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

#ifdef	DEBUG
#define	LOG(str) std::cout << "LOG: " << str << std::endl;
#else
#define	LOG(str)
#endif

class Bureaucrat;

class Form
{
	public:
		Form(std::string &name, int signGrade, int execGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);
		
		class	GradeTooHighException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};

		void	beSigned(const Bureaucrat &bureaucrat);

		std::string getName(void) const;
		int	getSignGrade(void) const;
		int	getExecGrade(void) const;
		bool	getIsSigned(void) const;

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif