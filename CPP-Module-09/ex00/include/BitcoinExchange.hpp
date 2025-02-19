
#ifndef	BITCOINEXCHANGE_HPP
#define	BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

#ifdef DEBUG
#define LOG(str) std::cout << str << std::endl;
#else
#define LOG(str)
#endif

class Bitcoin
{
	public:
		Bitcoin(void);
		Bitcoin(const Bitcoin &rhs);
		Bitcoin	&operator=(const Bitcoin &rhs);
		~Bitcoin(void);

	private:
		std::map<std::string, float>	_db;
		
};

#endif