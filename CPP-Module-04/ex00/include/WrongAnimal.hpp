
#ifndef WRONGANIMAL_H
#define	WRONGANIMAL_H

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		virtual ~WrongAnimal(void);

		std::string	getType() const;
		void	setType(std::string type);

		virtual void	makeSound() const;
	private:
		std::string	_type;
};

#endif