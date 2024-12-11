
#ifndef DOG_H
#define DOG_H

#include "../include/Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog(void);

		void makeSound(void) const;
};

std::ostream &operator<<(std::ostream &ofs, const Dog &dog);

#endif