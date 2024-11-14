
#ifndef BRAIN_H
#define	BRAIN_H

#include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain(void);

		void	setIdea(const std::string &idea, int index);
		void	printIdeas(void);
		std::string	getIdea(int index) const;
		int	getNbIdea(void);

	private:
		std::string	_ideas[100];
		int			_nbIdeas;

};

#endif