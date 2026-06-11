/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:07:05 by jjorda            #+#    #+#             */
/*   Updated: 2026/06/02 18:31:13 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <ctime>

void	FormExec(AForm *f, const Bureaucrat &boss, const Bureaucrat &badBoy)
{
	if (f)
	{
		f->beSigned(boss);
		boss.executeForm(*f);
		badBoy.executeForm(*f);
	}
}

int main(void)
{
	std::srand(std::time(NULL));

	Bureaucrat	boss("Boss", 1);
	Bureaucrat	badBoy("The Bad Boy", 150);
	Intern someRandomIntern;

	AForm* f1 = someRandomIntern.makeForm("robotomy request", "Bender");
	FormExec(f1, boss, badBoy);
	
	AForm* f2 = someRandomIntern.makeForm("shrubbery creation", "garden");
	FormExec(f2, boss, badBoy);
	
	AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Arthur");
	FormExec(f3, boss, badBoy);
	
	AForm* f4 = someRandomIntern.makeForm("invalid form", "nobody");
	FormExec(f4, boss, badBoy);

	delete f1;
	delete f2;
	delete f3;
	delete f4;
	return (0);
}
