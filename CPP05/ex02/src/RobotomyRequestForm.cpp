#include "RobotomyRequestForm.hpp"

using std::cout;
using std::endl;

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy form", 72, 45), _target("Robotomy")
{
	cout << "Creation of standard " << endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy form", 72, 45), _target(target)
{
	cout << "Creation of " << target << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
	cout << "Creation of a copy of " << other._target << endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		cout << "Assignation of a copy of " << other._target << endl;
		AForm::operator=(other);
		_target = other._target;
	}
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "Destruction of " << _target << endl;
}

void	RobotomyRequestForm::_executeAction(Bureaucrat const & executor) const
{
	(void) executor;
	cout << DRILL << endl;
	if (std::rand() % 2 == 0)
		cout << _target << FAILED_RBTMZD << endl;
	else
		cout << _target << SUCCES_RBTMZD << endl;
}
