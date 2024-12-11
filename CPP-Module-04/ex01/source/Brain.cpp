
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

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

int	Brain::getNbIdea(void) { return (_nbIdeas); }

std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		throw std::runtime_error("Index out of range");
	return (_ideas[index]);
}

void	Brain::setIdea(const std::string &idea, int index)
{
	if (0 <= index  and index < 100)
	{
		_nbIdeas++;
		_ideas[index] = idea;
	}
	else
		throw std::runtime_error("Index out of range");
}

void	Brain::printIdeas(void)
{
	for (int i = 0; i < this->getNbIdea(); i++)
		std::cout << i << ": " << _ideas[i] << std::endl;
}