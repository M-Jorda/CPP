#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

Intern::Intern()
{
	cout << "Creation of standard Intern" << endl;
}

Intern::Intern(const Intern& other)
{
	(void) other;
	cout << "Creation of a copy of another Intern" << endl;
}

Intern&	Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
		(void) other;
		cout << "Assignation of a copy of another Intern" << endl;
	}
    return (*this);
}

Intern::~Intern()
{
	cout << "Destruction of the Intern" << endl;
}

static AForm	*createRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm	*createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string FormName, std::string target)
{
	FormEntry table[] = {
		{ "robotomy request", &createRobotomy },
		{ "shrubbery creation", &createShrubbery },
		{ "presidential pardon", &createPardon }
	};

	for (int i = 0; i < 3; i++)
		if (FormName == table[i].name)
		{
			cout << "Intern creates " << FormName << endl;
			return (table[i].create(target));
		}
	cerr << "Error: Intern couldn't create " << FormName << " because it doesn't exist" << endl;
	return (NULL);
}
