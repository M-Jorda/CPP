/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:07:05 by jjorda            #+#    #+#             */
/*   Updated: 2026/06/02 18:07:11 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Intern someRandomIntern;
    AForm* f1 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* f2 = someRandomIntern.makeForm("shrubbery creation", "garden");
    AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Arthur");
    AForm* f4 = someRandomIntern.makeForm("invalid form", "nobody");

    delete f1;
    delete f2;
    delete f3;
    delete f4;
}
