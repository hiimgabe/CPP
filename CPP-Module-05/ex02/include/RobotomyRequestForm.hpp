
#ifndef	ROBOTOMY_H
#define	ROBOTOMY_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm(void);

		void	execute(void) const;
	
	private:
		std::string	_target;
};

#endif
