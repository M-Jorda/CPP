#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class	ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(type name);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

	private:
		type _name;
};

#endif
