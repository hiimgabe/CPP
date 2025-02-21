
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

	file.open("subject-test-files/data.csv", std::ios::in);
	if (file.fail())
		std::cerr << "Couldn't open data.csv" << std::endl;
	std::getline(file, buffer);
	while(std::getline(file, buffer))
	{
		curr.first = strToTime(buffer.substr(0, buffer.find(',')).c_str());
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
		std::cerr << "Invalid date." << str << std::endl;
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

bool	Bitcoin::checkValue(float value)
{
	if (value < 0)
		return (false);
	else if (value > 1000)
		return (false);
	return (true);
}

bool	Bitcoin::checkDate(const std::string &date)
{
	std::string	res = timeToStr(strToTime(date));
	return (date == res);
}

bool	Bitcoin::isOnlySpace(const std::string &str)
{
	//std::cout << "checking if only spaces for : _" << str << "_" << std::endl;
	for (size_t i = 0; i < str.size(); i++)
	{
		//std::cout << "str[i] = _" << str[i] << "_" << std::endl; 
		if (!isspace(str[i]))
			return (true);
	}
	return (false);
}

bool	Bitcoin::checkValueNb(const std::string &str)
{
	if (!isOnlySpace(str))
		return (false);
	for (size_t i = 0; i < str.size(); i++)
		if (!isdigit(str[i]) && !isspace(str[i]) && str[i] != 46)
			return (false);
	return (true);
}

std::time_t	Bitcoin::getBtValue(const std::string &date)
{
	std::map<std::time_t, float>::iterator it;
	std::time_t	dateTime_t = strToTime(date);

	for(it = _db.begin(); it != _db.end(); ++it)
	{
		if (it->first == dateTime_t)
			return (it->first);
		if (it->first > dateTime_t)
		{
			--it;
			return (it->first);
		}
	}
	return (_db.begin()->first);
}

void	Bitcoin::runInput(const std::pair<std::string, std::string> &input)
{
	std::string	strInput = input.first;
	float	floatInput = std::strtof(input.second.c_str(), NULL);

	if (!checkValueNb(input.second))
		return(LOG_ERR("Error: Invalid input => " + input.second), void());
	if (!checkDate(strInput))
		return (LOG_ERR("Error: Invalid input => " + strInput), void());
	if (!checkValue(floatInput))
		return (LOG_ERR("Error: Invalid number => " + input.second), void());
	float	bcValue = _db[getBtValue(strInput)];
	std::cout << input.first << " => " << input.second << " = " << floatInput * bcValue << std::endl;
}

void	Bitcoin::runBitcoin(void)
{
	std::ifstream	inputFile;
	std::string	buffer;
	std::pair<std::string, std::string>	curr;

	inputFile.open(_file.c_str(), std::ios::in);
	if (inputFile.fail())
		std::cerr << "Error: Invalid file: " << _file << std::endl;
	std::getline(inputFile, buffer);
	while (std::getline(inputFile, buffer))
	{
		curr.first = buffer.substr(0, buffer.find(" |")).c_str();
		curr.second = buffer.substr(buffer.find('|') + 1).c_str();
		runInput(curr);
	}
}