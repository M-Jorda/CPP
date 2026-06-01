/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:46:04 by jjorda            #+#    #+#             */
/*   Updated: 2026/05/18 18:46:05 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

using std::cout;
using std::endl;

AForm::AForm() : _name("Robert"), _gradeToSign(1), _gradeToExecute(1)
{
	_isSigned = false;
	cout << "Creation of standard " << "Robert" << endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	_isSigned = false;
	cout << "Creation of " << name << endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	_isSigned = false;
	cout << "Creation of a copy of " << other._name << endl;
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
    {
		_isSigned = false;
    }
    return (*this);
}

AForm::~AForm()
{
	cout << "Destruction of " << _name << endl;
}

std::string	AForm::getName() const
{
	return (_name);
}

int	AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const & executor)
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	if (executor.getGrade() < _gradeToExecute)
		throw GradeTooHighException();
	_executeAction(executor);
}

const char*	AForm::GradeTooHighException::what()	const throw()
{
	return ("Grade is too high (Min 1)");
}

const char*	AForm::GradeTooLowException::what()	const throw()
{
	return ("Grade is too low (Max 150)");
}

const char*	AForm::FormNotSignedException::what()	const throw()
{
	return ("This form is not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& other)
{
	os << "Name: " << other.getName() << endl;
	os << "IsSigned: " << (other.getIsSigned() ? "true" : "false") << endl;
	os << "GradeToSign: " << other.getGradeToSign() << endl;
	os << "GradeToExecute: " << other.getGradeToExecute() << endl;
	return os;
}
