
#include "../include/Brain.hpp"

Brain::Brain(void) : _nbIdeas(0) { std::cout << "Brain default constructor called" << std::endl; }

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain copy constructor called." << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
		_nbIdeas = other._nbIdeas;
	}
	return (*this);
}

Brain::~Brain(void) { std::cout << "Brain destructor called" << std::endl; }

int	Brain::getNbIdea(void) { return (_nbIdeas); }

std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		throw std::runtime_error("Index out of range");
	return (_ideas[index]);
}

void	Brain::setIdea(const std::string &idea, int index)
{
	if (index < 0 || index >= 100)
		throw std::runtime_error("Index out of range");
	_ideas[index] = idea;
	_nbIdeas++;
}

void	Brain::printIdeas(void)
{
	for (int i = 0; i < _nbIdeas; i++)
		std::cout << _ideas[i] << std::endl;
}