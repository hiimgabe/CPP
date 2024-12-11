
#ifndef WRONGCAT_H
#define	WRONGCAT_H

#include "../include/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat &other);
		WrongCat&operator=(const WrongCat &other);
		~WrongCat(void);

		void makeSound() const;
};

std::ostream &operator<<(std::ostream &ofs, const WrongCat &wrongAnimal);

#endif