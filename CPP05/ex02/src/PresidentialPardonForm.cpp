#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm() : _name(<name>)
{
	cout << "Creation of standard " << endl;
}

PresidentialPardonForm::PresidentialPardonForm(type name) : _name(name)
{
	cout << "Creation of " << name << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : _name(other._name)
{
	cout << "Creation of a copy of " << other._name << endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
    {
		cout << "Assignation of a copy of " << other._name << endl;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "Destruction of " << _name << endl;
}

