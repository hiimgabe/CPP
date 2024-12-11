
#ifndef ANIMAL_H
#define	ANIMAL_H

#include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal(void);

		std::string	getType(void) const;
		void	setType(const std::string &type);

		virtual void	makeSound(void) const;
	private:
		std::string	_type;
};

std::ostream &operator<<(std::ostream &ofs, const Animal &animal);

#endif