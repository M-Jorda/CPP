#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cmath>
# include <cctype>
# include <limits>
# include <iomanip>

# include "Macro.hpp"

class	ScalarConverter
{
	public:
		~ScalarConverter();
		static void	convert(std::string toConvert);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
};

enum eType {CHAR, INT, DOUBLE, FLOAT, INV};

#endif
