/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 12:57:38 by jjorda            #+#    #+#             */
/*   Updated: 2026/05/15 13:38:08 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

Bureaucrat::Bureaucrat() : _name("Robert")
{
	_grade = 150;
	cout << "Creation of standard " << "Robert" << endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade <= 1)
		throw GradeTooHighException();
	if (grade >= 150)
		throw GradeTooLowException();
	_grade = grade;
	cout << "Creation of " << name << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	if (other._grade <= 1)
		throw GradeTooHighException();
	if (other._grade >= 150)
		throw GradeTooLowException();
	_grade = other._grade;
	cout << "Creation of a copy of " << other._name << endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
    {
		cout << "Assignation of a copy of " << other._name << endl;
		if (other._grade <= 1)
			throw GradeTooHighException();
		if (other._grade >= 150)
			throw GradeTooLowException();
		_grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
	cout << "Destruction of " << _name << endl;
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what()	const throw()
{
	return ("Grade is too high (Min 1)");
}

const char*	Bureaucrat::GradeTooLowException::what()	const throw()
{
	return ("Grade is too low (Max 150)");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return os;
}
