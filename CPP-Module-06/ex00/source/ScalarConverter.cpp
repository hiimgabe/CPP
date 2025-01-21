
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

bool	ScalarConverter::isSpecialValue(const std::string &value)
{
	if (value == "nan" || value == "nanf"
		|| value == "-inf" || value == "+inf" || value == "inf"
		|| value == "-inff" || value == "+inff" || value == "inff")
		return (true);
	return (false);
}

float	ScalarConverter::floatSpecialConvertion(const std::string &value)
{
	if (value == "nan" || value == "nanf")
		return (std::numeric_limits<float>::quiet_NaN());
	else if (value == "+inff" || value == "inff" || value == "+inf" || value == "inf")
		return (std::numeric_limits<float>::infinity());
	else if (value == "-inff" || value == "-inf")
		return (-std::numeric_limits<float>::infinity());
	return (std::strtof(value.c_str(), NULL));
}

double	ScalarConverter::doubleSpecialConvertion(const std::string &value)
{
	if (value == "nan" || value == "nanf")
		return (std::numeric_limits<double>::quiet_NaN());
	else if (value == "+inff" || value == "inff" || value == "+inf" || value == "inf")
		return (std::numeric_limits<double>::infinity());
	else if (value == "-inff" || value == "-inf")
		return (-std::numeric_limits<double>::infinity());
	return (std::strtod(value.c_str(), NULL));
}

void	ScalarConverter::specialConvertion(const std::string &value)
{
	float	fValue = floatSpecialConvertion(value);
	double	dValue = doubleSpecialConvertion(value);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << fValue << "f" << std::endl;
	std::cout << "double: " << dValue << std::endl;
}

bool	ScalarConverter::valueIsChar(const std::string &value)
{
	return (value.length() == 1 && ((value[0] >= 33 && value[0] <= 47 ) || (value[0] >= 58 && value[0] <= 126)));
}

bool	ScalarConverter::valueIsInt(const std::string &value) { return (isOnlyDigit(value)); }

bool	ScalarConverter::isOnlyDigit(const std::string &value)
{
	size_t sign = 0;
	if (value[0] == '-' || value[0] == '+')
		sign++;
	for (size_t i =+ sign; i < value.length(); i++)
		if (!isdigit(value[i]))
			return (false);
	return (true);
}

void	ScalarConverter::standardConvertion(const std::string &value)
{
	if (valueIsChar(value))
		std::cout << value << " is a char" << std::endl;
	else if (valueIsInt(value))
		std::cout << value << " is a int" << std::endl;
	else
		std::cout << value << " is tolo" << std::endl;
}

void	ScalarConverter::convert(const std::string &value)
{
	std::cout << "Converting : " << value << std::endl;
	if (isSpecialValue(value))
		specialConvertion(value);
	else
		standardConvertion(value);
}

