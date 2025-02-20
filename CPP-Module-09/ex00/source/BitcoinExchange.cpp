
#include "../include/BitcoinExchange.hpp"

Bitcoin::Bitcoin(void): _file(NULL)
{
	LOG("Bitcoin Default Constructor called.");
	loadData();
}

Bitcoin::Bitcoin(const std::string &file): _file(file)
{
	loadData();
}

Bitcoin::Bitcoin(const Bitcoin &rhs)
{
	LOG ("Bitcoin Copy Constructor called.");
	*this = rhs;
}

Bitcoin	&Bitcoin::operator=(const Bitcoin &rhs)
{
	LOG("Bitcoin Assign Operator called.");
	if (this != &rhs)
	{
		_db = rhs._db;
		_file = rhs._file;
	}
	return (*this);
}

Bitcoin::~Bitcoin(void)
{
	LOG("Bitcoin Destructor called.");
}

void	Bitcoin::loadData(void)
{
	std::ifstream	file;
	std::string		buffer;
	std::pair<std::time_t, float>	curr;

	file.open("data.csv", std::ios::in);
	if (file.fail())
		std::cerr << "Couldn't open data.csv" << std::endl;
	else
		std::cout << "Opened data.csv successfully" << std::endl;
	std::getline(file, buffer); // get the 1st line -> date,exchange_rate
	while(std::getline(file, buffer))
	{
		curr.first = strToTime(buffer.substr(0, buffer.find(',')));
		curr.second = std::strtof(buffer.substr(buffer.find(',') + 1).c_str(), NULL);
		_db.insert(curr);
	}
	file.close();
}

std::time_t	Bitcoin::strToTime(const std::string &str)
{
	std::tm	tm = {};
	int	y, m, d;

	if (sscanf(str.c_str(), "%4d-%2d-%2d", &y, &m, &d) != 3)
		std::cout << "Invalid date." << str << std::endl;
	else
	{
		tm.tm_year = y - 1900;
		tm.tm_mon = m - 1;
		tm.tm_mday = d;
	}
	return (mktime(&tm));//	converts std::tm to std::time_t in "time since epoch"
}

std::string	Bitcoin::timeToStr(const std::time_t &time)
{
	char	res[12];
	std::tm	*tmp = std::localtime(&time);
	std::strftime(res, sizeof(res), "%Y-%m-%d", tmp);

	return (res);
}

void	Bitcoin::runBitcoin(void)
{
	std::ifstream	inputFile;
	std::string	buffer;
	std::pair<std::time_t, float>	curr;

	std::cout << "running on file: " << _file << std::endl;
	inputFile.open(_file.c_str(), std::ios::in);
	if (inputFile.fail())
		std::cerr << "Error: Invalid file: " << _file << std::endl;
}