
#include "../include/AMateria.hpp"

AMateria::AMateria(void) { std::cout << "AMateria default constructor called." << std::endl; }

AMateria::AMateria(std::string const & type) : _type(type) { std::cout << "AMateria copy constructor called." << std::endl; }

AMateria::~AMateria(void) { std::cout << "AMateria destructor called." << std::endl; }

const	std::string& AMateria::getType(void) const { return (_type); }

void	AMateria::use(ICharacter& target) { (void)target; }

bool	AMateria::getInUse(void) { return (_inUse); }

void	AMateria::setInUse(bool value) { _inUse = value; }