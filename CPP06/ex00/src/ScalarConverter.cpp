#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{
}

static void	printSol(eType type, std::string str)
{
	std::string charType = NULL;
	switch (type)
	{
	case INT:
		charType = "int";
		break;
	case FLOAT:
		charType = "float";
		break;
	case DOUBLE:
		charType = "double";
		break;
	case CHAR:
		charType = "char";
		break;
	}
	std::cout << charType << ": " << str << std::endl;
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
		return (std::strtol(str.c_str(), &endpoint, 10));
	case FLOAT:
	case DOUBLE:
		return (std::strtod(str.c_str(), &endpoint));
	default:
		return (0.0);
	}
}

static void	printChar(double value, eType type)
{
	if (std::isnan(value) || std::isinf(value))
		printSol(type, IMP);
	if (value < 127 && value > 0)
		printSol(type, IMP);
	if (!std::isprint(value))
		printSol(type, NONDISP);
	printSol(type, static_cast<char>(value));
}

void	ScalarConverter::convert(std::string toConvert)
{
	eType	type = detectType(toConvert);
	double	value = getDoubleValue(toConvert, type);

	printChar(value, type);
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
    return (*this);
}
