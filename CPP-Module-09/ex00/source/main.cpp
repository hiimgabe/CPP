
#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <map>
#include <ctime>
#include <time.h>


int	main(int argc, char **argv)
{
/*	std::ifstream	file;
	std::string	buffer;
	std::map<std::time_t, float>	content;
	std::pair<std::time_t, float>	curr;

//	open file
	file.open("data.csv");
	if (file.fail())
		std::cerr << "fail file" << std::endl;
	else
		std::cout << "file success" << std::endl;
	std::getline(file, buffer);
	//std::cout << "first line" << buffer << std::endl;
//	read and save file into map
	while (std::getline(file, buffer))
	{
		//	use of std::pair<time_t, float> to store information inside std::map
		//	time_t	: date (Year-Month-Day)
		//	float	: value 
		curr.first = strToTime(buffer.substr(0, buffer.find(',')));
		curr.second = std::strtof(buffer.substr(buffer.find(',') + 1).c_str(), NULL);
		content.insert(curr);
	}

//	time_t to str
	std::map<std::time_t, float>::iterator	it;
	//for (it = content.begin(); it != content.end(); ++it)
	//{
		it = content.begin();
		std::tm	*tmp = std::localtime(&it->first);
		char	tmpBuff[20];
		std::strftime(tmpBuff, sizeof(tmpBuff), "%Y-%m-%d", tmp);
		std::cout << tmpBuff << std::endl;
	//}

	//std::string	test1 = "2012-12-11,0.21";
	//std::string	test2 = "2012-12-11 | 1";
//
	//std::time_t t1 = strToTime(test1.substr(0, test1.find(',')));
	//std::time_t t2 = strToTime(test2.substr(0, test2.find('|')));
//
	//std::cout << "t1: " << t1 << "\nt2: " << t2 << std::endl;
	//std::string	rest1 = timeToStr(t1);
	//std::string	rest2 = timeToStr(t2);
	//std::cout << "rest1: " << rest1 << "\nrest2: " << rest2 << std::endl;
*/
	if (argc == 2)
	{
		Bitcoin btc(argv[1]);
		btc.runBitcoin();
	}
	else
		std::cerr << "Error: correct usage: ./btc <input.txt>" << std::endl;

	return (0);
}