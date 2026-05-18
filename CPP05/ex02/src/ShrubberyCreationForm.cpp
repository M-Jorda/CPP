#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm() : _name(<name>)
{
	cout << "Creation of standard " << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(type name) : _name(name)
{
	cout << "Creation of " << name << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : _name(other._name)
{
	cout << "Creation of a copy of " << other._name << endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
    {
		cout << "Assignation of a copy of " << other._name << endl;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "Destruction of " << _name << endl;
}

