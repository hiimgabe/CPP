
#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) { LOG("ScalarConverter Default Constructor called."); }

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	LOG("ScalarConverter Copy Constructor called.");
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	LOG("ScalarConverter Assign Operator Constructor called.");
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) { LOG("ScalarConverter Default Destructor called."); }

bool	ScalarConverter::isSpecialValue(std::string &value)
{
	if (value == "nan" || value == "nanf"
		|| value == "-inf" || value == "+inf" || value == "inf"
		|| value == "-inff" || value == "+inff" || value == "inff")
		return (true);
	return (false);
}

float	ScalarConverter::floatSpecialConvertion(std::string &value)
{
	if (value == "nan" || value == "nanf")
		return (std::numeric_limits<float>::quiet_NaN());
	else if (value == "+inff" || value == "inff" || value == "+inf" || value == "inf")
		return (std::numeric_limits<float>::infinity());
	else if (value == "-inff" || value == "-inf")
		return (-std::numeric_limits<float>::infinity());
	return (std::strtof(value.c_str(), NULL));
}

double	ScalarConverter::doubleSpecialConvertion(std::string &value)
{
	if (value == "nan" || value == "nanf")
		return (std::numeric_limits<double>::quiet_NaN());
	else if (value == "+inff" || value == "inff" || value == "+inf" || value == "inf")
		return (std::numeric_limits<double>::infinity());
	else if (value == "-inff" || value == "-inf")
		return (-std::numeric_limits<double>::infinity());
	return (std::strtod(value.c_str(), NULL));
}

void	ScalarConverter::specialConvertion(std::string &value)
{
	float	fValue = floatSpecialConvertion(value);
	double	dValue = doubleSpecialConvertion(value);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << fValue << "f" << std::endl;
	std::cout << "double: " << dValue << std::endl;
}

bool	ScalarConverter::valueIsChar(std::string &value)
{
	return (value.length() == 1 && ((value[0] >= 33 && value[0] <= 47 ) || (value[0] >= 58 && value[0] <= 126)));
}

bool	ScalarConverter::valueIsInt(std::string &value) { return (isNumber(value)); }

bool	ScalarConverter::isNumber(std::string &value)
{
	size_t sign = 0;

	if (value[0] == '-' || value[0] == '+')
		sign++;
	if (sign >= 1 && value.length() == 1)
		return (false);
	for (size_t i = sign; i < value.length(); i++)
		if (!isdigit(value[i]))
			return (false);
	return (true);
}

bool	ScalarConverter::valueIsDouble(std::string &value)
{
	size_t		sign = 0;
	std::string	split[2];

	if (value[0] == '-' || value[0] == '+')
		sign++;
	if (validDot(value))
	{
		size_t	dotPos = value.find('.');
		split[0] = value.substr(0, dotPos);
		split[1] = value.substr(dotPos + 1);
		if (isNumber(split[0]) && isOnlyDigit(split[1]))
			return (true);
	}
	return (false);
}

bool	ScalarConverter::isOnlyDigit(std::string &value)
{
	for (size_t i = 0; i < value.length(); i++)
		if (!isdigit(value[i]))
			return (false);
	return (true);
}

bool	ScalarConverter::validDot(std::string &value)
{
	int			dotCount = 0;
	std::string	split[2];

	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] == '.')
			dotCount++;
		if (dotCount > 1)
			return (false);
	}
	if (dotCount < 1)
		return (false);
	size_t	dotPos = value.find('.');
	if (dotPos != std::string::npos)
	{
		split[0] = value.substr(0, dotPos);
		split[1] = value.substr(dotPos + 1);
		if (split[0].empty() || split[1].empty())
			return (false);
	}
	return (true);
}

bool	ScalarConverter::valueIsFloat(std::string &value)
{
	std::string	split[2];
	
	if (validDot(value))
	{
		size_t	dotPos = value.find('.');
		split[0] = value.substr(0, dotPos);
		split[1] = value.substr(dotPos + 1);
		if (isNumber(split[0]) && isFloatEnd(split[1]))
			return (true);
	}
	return (false);
}

bool	ScalarConverter::isFloatEnd(std::string &value)
{
	if (!isdigit(value[0]))
		return (false);
	for (size_t i = 0; i < value.length() - 1; i++)
		if (!isdigit(value[i]))
			return (false);
	if (value[value.length() - 1] == 'f')
		return (true);
	return (false);
}

void	ScalarConverter::convertFromChar(std::string &value)
{
	LOG("Converting " + value + " from char.");
	char	c = value[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	ScalarConverter::printConvertion(c, i, f, d);
}

void	ScalarConverter::convertFromInt(std::string &value)
{
	LOG("Converting " + value + " from int.");
	int		i = atoi(value.c_str());
	char	c = static_cast<unsigned char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	ScalarConverter::printConvertion(c, i, f, d);
}

void	ScalarConverter::convertFromFloat(std::string &value)
{
	double	overflowCheck = strtod(value.c_str(), NULL);
	if (overflowCheck < INT_MIN || overflowCheck > INT_MAX)
	{
		printIntOverflow(value);
		return ;
	}
	LOG("Converting " + value + " from float.");
	float	f = atof(value.c_str());
	int		i = static_cast<int>(f);
	char	c = static_cast<unsigned char>(f);
	double	d = static_cast<double>(f);

	ScalarConverter::printConvertion(c, i, f, d);
}

void	ScalarConverter::convertFromDouble(std::string &value)
{
	double	overflowCheck = strtod(value.c_str(), NULL);
	if (overflowCheck < INT_MIN || overflowCheck > INT_MAX)
	{
		printIntOverflow(value);
		return ;
	}
	LOG("Converting " + value + " from double.");
	double	d = strtod(value.c_str(), NULL);
	float	f = static_cast<float>(d);
	int		i = static_cast<int>(d);
	char	c = static_cast<unsigned char>(d);

	ScalarConverter::printConvertion(c, i, f, d);
}

bool	ScalarConverter::isDisplayable(int i) { return (i >= 32 && i <= 126); }

void	ScalarConverter::printIntOverflow(std::string &value)
{
	LOG("Converting " + value + " from intOverflow");
	std::cout << "char: Overflows" << std::endl;
	std::cout << "int: Overflows" << std::endl;
	std::cout << "float: " << strtof(value.c_str(), NULL) << "f" << std::endl;
	std::cout << "double: " << strtod(value.c_str(), NULL) << std::endl;
}

void	ScalarConverter::printConvertion(char c, int i, float f, double d)
{
	if (i > 127 || i < -128)
		std::cout << "char: Overflows" << std::endl;
	else
	{
		if (!isDisplayable(i))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << c << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::standardConvertion(std::string &value)
{
	double	overflowCheck = strtod(value.c_str(), NULL);

	if (valueIsChar(value))
	{
		ScalarConverter::convertFromChar(value);
		return;
	}
	else if (valueIsInt(value) && overflowCheck > INT_MIN && overflowCheck < INT_MAX)
	{
		ScalarConverter::convertFromInt(value);
		return ;
	}
	else if (valueIsDouble(value))
	{
		ScalarConverter::convertFromDouble(value);
		return ;
	}
	else if (valueIsFloat(value))
	{
		ScalarConverter::convertFromFloat(value);
		return ;
	}
	else if ((overflowCheck > INT_MAX || overflowCheck < INT_MIN) && valueIsInt(value))
		ScalarConverter::printIntOverflow(value);
	else
		throw ConvertionImpossible();
}

void	ScalarConverter::convert(std::string &value)
{
	std::cout << "Converting : " << value << '\n' << std::endl;
	if (isSpecialValue(value))
		specialConvertion(value);
	else
		standardConvertion(value);
}

const char	*ScalarConverter::ConvertionImpossible::what(void) const throw() { return ("Impossible to convert."); }