#include "ScalarConverter.hpp"

using std::cout;
using std::endl;

ScalarConverter::ScalarConverter() : _name(<name>)
{
	cout << "Creation of standard " << endl;
}

ScalarConverter::ScalarConverter(type name) : _name(name)
{
	cout << "Creation of " << name << endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) : _name(other._name)
{
	cout << "Creation of a copy of " << other._name << endl;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other)
    {
		cout << "Assignation of a copy of " << other._name << endl;
    }
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
	cout << "Destruction of " << _name << endl;
}

