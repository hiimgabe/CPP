
#ifndef AMATERIA_H
#define	AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(std::string const &type);
		virtual ~AMateria(void);

		const std::string& getType(void) const;

		virtual	AMateria* clone(void) const = 0;
		virtual	void use(ICharacter& target);
	
		bool getInUse(void);
		void setInUse(bool value);
	protected:
		std::string	_type;
		bool		_inUse;
};

#endif

/*
	Of course, their member function
	clone() will return a new instance of the same type (i.e., if you clone an Ice Materia,
	you will get a new Ice Materia).

	The use(ICharacter&) member function will display:
	• Ice: "* shoots an ice bolt at <name> *"
	• Cure: "* heals <name>’s wounds *"

	<name> is the name of the Character passed as parameter. Don’t print the angle
	brackets (< and >).
*/