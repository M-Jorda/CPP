#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery form", 145, 137), _target("Shrubby")
{
	cout << "Creation of standard " << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery form", 145, 137), _target(target)
{
	cout << "Creation of " << target << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
	cout << "Creation of a copy of " << other._target << endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
    {
		cout << "Assignation of a copy of " << other._target << endl;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "Destruction of " << _target << endl;
}

void	ShrubberyCreationForm::_executeAction(Bureaucrat const & executor) const
{
	(void) executor;
	std::string	line;
	std::string	content;

	std::string outputFileName(_target);
	outputFileName += SHRUBNAME;
	std::ofstream	outputFile(outputFileName.c_str());
	if (!outputFile.is_open())
		throw FileNotCreatedException();
	outputFile << SHRUBTREES;
	outputFile.close();
}

const char*	ShrubberyCreationForm::FileNotCreatedException::what()	const throw()
{
	return (ERRCREATE);
}
