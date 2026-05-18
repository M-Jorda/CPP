#include "RobotomyRequestForm.hpp"

using std::cout;
using std::endl;

RobotomyRequestForm::RobotomyRequestForm() : _name(<name>)
{
	cout << "Creation of standard " << endl;
}

RobotomyRequestForm::RobotomyRequestForm(type name) : _name(name)
{
	cout << "Creation of " << name << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : _name(other._name)
{
	cout << "Creation of a copy of " << other._name << endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
    {
		cout << "Assignation of a copy of " << other._name << endl;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "Destruction of " << _name << endl;
}

