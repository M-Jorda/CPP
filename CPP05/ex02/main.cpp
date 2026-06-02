/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:07:05 by jjorda            #+#    #+#             */
/*   Updated: 2026/06/02 17:04:03 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <ctime>

using std::cout;
using std::cerr;
using std::endl;

int	main(void)
{
	std::srand(std::time(NULL));

	cout << "=== Invalid grades at construction ===" << endl;
	try { Bureaucrat tooHigh("Icarus", 0); }
	catch (std::exception &e) { cerr << "Error: " << e.what() << endl; }
	try { Bureaucrat tooLow("Mole", 151); }
	catch (std::exception &e) { cerr << "Error: " << e.what() << endl; }

	cout << "\n=== Execute an unsigned form ===" << endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Arthur");
		boss.executeForm(pardon);
	}
	catch (std::exception &e) { cerr << "Error: " << e.what() << endl; }

	cout << "\n=== Signed, but grade too low to execute ===" << endl;
	try
	{
		Bureaucrat clerk("Clerk", 20); // signs (<= 25) but can't execute (> 5)
		PresidentialPardonForm pardon("Arthur");
		pardon.beSigned(clerk);
		clerk.executeForm(pardon);
	}
	catch (std::exception &e) { cerr << "Error: " << e.what() << endl; }

	cout << "\n=== Each form signed and executed successfully ===" << endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur");

		shrub.beSigned(boss);
		boss.executeForm(shrub);

		robot.beSigned(boss);
		boss.executeForm(robot);

		pardon.beSigned(boss);
		boss.executeForm(pardon);
	}
	catch (std::exception &e) { cerr << "Error: " << e.what() << endl; }

	return (0);
}
