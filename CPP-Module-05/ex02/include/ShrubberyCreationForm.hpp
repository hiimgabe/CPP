
#ifndef	SHRUBBERY_H
#define	SHRUBBERY_H

#include "AForm.hpp"

class Shrubbery : public AForm
{
	public:
		Shrubbery(const std::string &name);
		Shrubbery(const Shrubbery &other);
		Shrubbery &operator=(const Shrubbery &other);
		~Shrubbery(void);

		//void	execute(const Bureaucrat &executor);
};

#endif