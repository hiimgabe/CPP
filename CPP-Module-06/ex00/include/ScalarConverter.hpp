
#ifndef	SCALARCONVERTER_HPP
#define	SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

#ifdef DEBUG
#define LOG(str) std::cout << str << std::endl;
#else
#define LOG(str)
#endif

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter(void);

		static bool	isSpecialValue(const std::string &value);

		static void	specialConvertion(const std::string &value);
		static void	standardConvertion(const std::string &value);

		static bool	valueIsChar(const std::string &value);

		static bool	valueIsInt(const std::string &value);
		static bool	isOnlyDigit(const std::string &value);

		static bool valueIsDouble(const std::string &value);
		static int	validDot(const std::string &value);

		static float	floatSpecialConvertion(const std::string &value);
		static double	doubleSpecialConvertion(const std::string &value);

	public:
		static void	convert(const std::string &value);
};

#endif