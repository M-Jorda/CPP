#include "Form.hpp"
#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

Form::Form() : _name("Robert"), _gradeToSign(1), _gradeToExecute(1)
{
	_isSigned = false;
	cout << "Creation of standard " << "Robert" << endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	_isSigned = false;
	cout << "Creation of " << name << endl;
}

Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	_isSigned = false;
	cout << "Creation of a copy of " << other._name << endl;
}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

Form::~Form()
{
	cout << "Destruction of " << _name << endl;
}

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char*	Form::GradeTooHighException::what()	const throw()
{
	return ("Grade is too high (Min 1)");
}

const char*	Form::GradeTooLowException::what()	const throw()
{
	return ("Grade is too low (Max 150)");
}

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os << "Name: " << other.getName() << endl;
	os << "IsSigned: " << (other.getIsSigned() ? "true" : "false") << endl;
	os << "GradeToSign: " << other.getGradeToSign() << endl;
	os << "GradeToExecute: " << other.getGradeToExecute() << endl;
	return os;
}
