
#ifndef	AFORM_H
#define	AFORM_H

#include <iostream>
#include "Bureaucrat.hpp"

#ifdef DEBUG
#define LOG(str) std::cout << str << std::endl;
#else
#define LOG(str)
#endif

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(const AForm &aForm);
		AForm &operator=(const AForm &aForm);
		virtual ~AForm(void);

		void	beSigned(const Bureaucrat &bureaucrat);
		//virtual void	execute(const Bureaucrat &executor) = 0;

		std::string	getName(void) const;
		int	getSignGrade(void) const;
		int	getExecGrade(void) const;
		bool	getIsSigned(void) const;

		void	setName(const std::string &name);
		void	setSignGrade(int signGrade);
		void	setExecGrade(int execGrade);
		void	setIsSigned(bool sign);

	private:
		std::string	_name;
		int			_signGrade;
		int			_execGrade;
		bool		_isSigned;
};

std::ostream &operator<<(std::ostream &os, AForm &form);

#endif