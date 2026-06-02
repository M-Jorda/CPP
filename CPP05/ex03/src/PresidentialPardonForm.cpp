/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:16:59 by jjorda            #+#    #+#             */
/*   Updated: 2026/06/02 16:15:46 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Form", 25, 5), _target("Mr Nobody")
{
	cout << "Creation of standard Mr Nobody" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Form", 25, 5), _target(target)
{
	cout << "Creation of " << target << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{
	cout << "Creation of a copy of " << other._target << endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		cout << "Assignation of a copy of " << other._target << endl;
		AForm::operator=(other);
		_target = other._target;
	}
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "Destruction of " << _target << endl;
}

void	PresidentialPardonForm::_executeAction(Bureaucrat const & executor) const
{
	(void) executor;
	cout << _target << PARDON << endl;
}

