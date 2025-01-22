
#ifndef	SCALARCONVERTER_HPP
#define	SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <climits>
#include <cstdlib>
#include <iomanip>

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

		static bool	isSpecialValue(std::string &value);

		static void	specialConvertion(std::string &value);
		static void	standardConvertion(std::string &value);

		static bool	valueIsChar(std::string &value);

		static bool	valueIsInt(std::string &value);
		static bool	isNumber(std::string &value);
		static bool	isOnlyDigit(std::string &value);

		static bool valueIsDouble(std::string &value);
		static bool	validDot(std::string &value);

		static bool valueIsFloat(std::string &value);
		static bool isFloatEnd(std::string &value);

		static bool	isDisplayable(int i);

		static void convertFromChar(std::string &value);
		static void convertFromInt(std::string &value);
		static void convertFromFloat(std::string &value);
		static void convertFromDouble(std::string &value);

		static void	printConvertion(char c, int i, float f, double d);
		static void	printIntOverflow(std::string &value);

		static float	floatSpecialConvertion(std::string &value);
		static double	doubleSpecialConvertion(std::string &value);

		class ConvertionImpossible : public std::exception
		{
			public:
				const char *what(void) const throw();
		};

	public:
		static void	convert(std::string &value);
};

#endif