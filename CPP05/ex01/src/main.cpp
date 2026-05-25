#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- Form valide ---" << std::endl;
	try
	{
		Form f("Tax Form", 50, 25);
		std::cout << f;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- GradeTooHighException (gradeToSign < 1) ---" << std::endl;
	try
	{
		Form f("Bad Form", 0, 25);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- GradeTooLowException (gradeToSign > 150) ---" << std::endl;
	try
	{
		Form f("Bad Form", 151, 25);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Signature reussie (grade suffisant) ---" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 10);
		Form f("Tax Form", 50, 25);
		boss.signForm(f);
		std::cout << f;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Signature echouee (grade insuffisant) ---" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 100);
		Form f("Tax Form", 50, 25);
		intern.signForm(f);
		std::cout << f;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Bureaucrat avec grade limite (exactement le grade requis) ---" << std::endl;
	try
	{
		Bureaucrat exact("Exact", 50);
		Form f("Tax Form", 50, 25);
		exact.signForm(f);
		std::cout << f;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
