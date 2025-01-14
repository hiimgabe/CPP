
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

		virtual void	execute(const Bureaucrat &executor) = 0;

	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_isSigned;
};

#endif