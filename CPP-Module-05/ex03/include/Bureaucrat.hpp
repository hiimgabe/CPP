
#ifndef	BUREAUCRAT_H
#define	BUREAUCRAT_H

#include <iostream>
#include "AForm.hpp"

#ifdef	DEBUG
#define	LOG(str) std::cout << "LOG: " << str << std::endl;
#else
#define	LOG(str)
#endif

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		void	promote(void);
		void	demote(void);
		void	executeForm(const AForm &form);

		std::string getName(void) const;
		int	getGrade(void) const;
		void	signForm(AForm &form);

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

		class	PromotionException: public std::exception
		{
			public:
				const char *what(void) const throw();
		};

		class	DemotionException: public std::exception
		{
			public:
				const char *what(void) const throw();
		};
	
	private:
		std::string	_name;
		int			_grade; 
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif