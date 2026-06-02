#include "Intern.hpp"

using std::cout;
using std::endl;

Intern::Intern() : _name(<name>)
{
	cout << "Creation of standard " << endl;
}

Intern::Intern(type name) : _name(name)
{
	cout << "Creation of " << name << endl;
}

Intern::Intern(const Intern& other) : _name(other._name)
{
	cout << "Creation of a copy of " << other._name << endl;
}

Intern&	Intern::operator=(const Intern& other)
{
	if (this != &other)
    {
		cout << "Assignation of a copy of " << other._name << endl;
    }
    return (*this);
}

Intern::~Intern()
{
	cout << "Destruction of " << _name << endl;
}

