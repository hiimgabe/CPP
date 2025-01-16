
#ifndef	FORM_H
#define	FORM_H

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

#ifdef	DEBUG
#define	LOG(str) std::cout << "LOG: " << str << std::endl;
#else
#define	LOG(str)
#endif

class Bureaucrat;

class AForm
{
	public:
		AForm(const std::string &name, int signGrade, int execGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm(void);
		
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

		class	FormSignException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};

		void	beSigned(const Bureaucrat &bureaucrat);
		void	execute(const Bureaucrat &executor) const;
		virtual void	execute(void) const = 0;

		std::string getName(void) const;
		int	getSignGrade(void) const;
		int	getExecGrade(void) const;
		bool	getIsSigned(void) const;

		void	setIsSigned(bool sign);

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif