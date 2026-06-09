/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:46:44 by jjorda            #+#    #+#             */
/*   Updated: 2026/06/09 13:19:55 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{
}

static eType	detectType(const std::string &str)
{
	char	*endpoint = NULL;

	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (CHAR);

	std::strtol(str.c_str(), &endpoint, 10);
	if (*endpoint == '\0')
		return (INT);
	
	std::strtod(str.c_str(), &endpoint);
	if (*endpoint == '\0')
		return (DOUBLE);
	if (*endpoint == 'f' && *(endpoint + 1) == '\0')
		return (FLOAT);

	return (INV);
}

static double	getDoubleValue(std::string str, eType type)
{
	char	*endpoint = NULL;

	switch (type)
	{
	case CHAR:
		return (static_cast<double>(str[1]));
	case INT:
	case FLOAT:
	case DOUBLE:
		return (std::strtod(str.c_str(), &endpoint));
	default:
		return (0.0);
	}
}

static void	printChar(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || (value > 127 || value < 0))
		std::cout << IMP << std::endl;
	else if (!std::isprint(value))
		std::cout << NONDISP << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void	printInt(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value)
			||value < std::numeric_limits<int>::min()
			|| value > std::numeric_limits<int>::max())
		std::cout << IMP << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

static void	printFloat(double value)
{
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << static_cast<float>(value) << "f" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

static void	printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << static_cast<float>(value) << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void	ScalarConverter::convert(std::string toConvert)
{
	eType	type = detectType(toConvert);
	if (type == INV)
	{
		std::cout << "char: " << IMP << std::endl;
		std::cout << "int: " << IMP << std::endl;
		std::cout << "float: " << IMP << std::endl;
		std::cout << "double: " << IMP << std::endl;
		return ;
	}

	double	value = getDoubleValue(toConvert, type);

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void) other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
    return (*this);
}
