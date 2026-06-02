/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:07:05 by jjorda            #+#    #+#             */
/*   Updated: 2026/06/02 16:43:47 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

int	main(void)
{
	std::srand(time(NULL));
	cout << "=== TEST 1: Execute without signing ===" << endl;
	try
	{
		Bureaucrat alice("Alice", 5);
		PresidentialPardonForm pardon("Zaphod");
		alice.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		cerr << "Error: " << e.what() << endl;
	}
	cout << endl;

	cout << "=== TEST 2: Sign and execute successfully ===" << endl;
	try
	{
		Bureaucrat alice("Alice", 5);
		PresidentialPardonForm pardon("Zaphod");
		pardon.beSigned(alice);
		alice.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		cerr << "Error: " << e.what() << endl;
	}
	cout << endl;

	cout << "=== TEST 3: Execute with insufficient grade ===" << endl;
	try
	{
		Bureaucrat bob("Bob", 50);
		PresidentialPardonForm pardon("Zaphod");
		pardon.beSigned(bob);
		bob.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		cerr << "Error: " << e.what() << endl;
	}
	cout << endl;

	cout << "=== TEST 4: Robotomy (50% success) ===" << endl;
	try
	{
		Bureaucrat charlie("Charlie", 20);
		RobotomyRequestForm robotomy("Bender");
		robotomy.beSigned(charlie);
		charlie.executeForm(robotomy);
		charlie.executeForm(robotomy);
		charlie.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		cerr << "Error: " << e.what() << endl;
	}
	cout << endl;

	cout << "=== TEST 5: Shrubbery creation ===" << endl;
	try
	{
		Bureaucrat dave("Dave", 137);
		ShrubberyCreationForm shrub("garden");
		shrub.beSigned(dave);
		dave.executeForm(shrub);
	}
	catch(const std::exception& e)
	{
		cerr << "Error: " << e.what() << endl;
	}
	cout << endl;

	return (0);
}