
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <map>
#include <ctime>
#include <time.h>

std::time_t	strToTime(const std::string &date)
{
	std::tm	tm = {};
	int	y, m, d;


	if (sscanf(date.c_str(), "%4d-%2d-%2d", &y, &m, &d) != 3)
		std::cout << "Invalid date." << date << std::endl;
	else
	{
		//std::cout << "valid date " << y << "-" << m << "-" << d << std::endl;
		tm.tm_year = y - 1900;
		tm.tm_mon = m - 1;
		tm.tm_mday = d;
	}
//	converts std::tm to std::time_t in "time since epoch"
	return (mktime(&tm));
}

int	main(void)
{
	std::ifstream	file;
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
	for (it = content.begin(); it != content.end(); ++it)
	{
		std::tm	*tmp = std::localtime(&it->first);
		char	tmpBuff[20];
		std::strftime(tmpBuff, sizeof(tmpBuff), "%Y-%m-%d", tmp);
		std::cout << tmpBuff << ": " << it->second << std::endl;
	}

	return (0);
}