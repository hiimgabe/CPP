
#ifndef DOG_H
#define DOG_H

#include "../include/AAnimal.hpp"

class Dog : public AAnimal
{
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog(void);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;
	
	private:
		Brain*	_brain;
};

#endif