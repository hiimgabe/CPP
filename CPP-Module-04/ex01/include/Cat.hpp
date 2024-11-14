
#ifndef CAT_H
#define CAT_H

#include "../include/Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat(void);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;
	
	private:
		Brain*	_brain;
};

#endif