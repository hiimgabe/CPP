
#ifndef	BITCOINEXCHANGE_HPP
#define	BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <ctime>
#include <cstdlib>

#define	LOG_ERR(str) std::cerr << str << std::endl

#ifdef DEBUG
#define LOG(str) std::cout << str << std::endl
#else
#define LOG(str)
#endif

class Bitcoin
{
	public:
		Bitcoin(void);
		Bitcoin(const std::string &file);
		Bitcoin(const Bitcoin &rhs);
		Bitcoin	&operator=(const Bitcoin &rhs);
		~Bitcoin(void);

		void	loadData(void);
		std::time_t	strToTime(const std::string &str);
		std::string	timeToStr(const std::time_t &time);

		void	runBitcoin();
		void	runInput(const std::pair<std::string, std::string> &input);

		bool	checkDate(const std::string &date);
		bool	checkValue(float value);
		bool	checkValueNb(const std::string &str);
		bool	isOnlySpace(const std::string &str);
		std::time_t	getBtValue(const std::string &date);

	private:
		std::map<std::time_t, float>	_db;
		std::string	_file;
		
};

#endif