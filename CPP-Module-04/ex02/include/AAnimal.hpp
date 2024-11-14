
#ifndef ANIMAL_H
#define	ANIMAL_H

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &other);
		virtual ~AAnimal(void);

		std::string	getType(void) const;
		void	setType(const std::string &type);

		virtual void	makeSound(void) const = 0;
	private:
		std::string	_type;
};

#endif