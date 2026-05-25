#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	std::cout << "--- Tests valides ---" << std::endl;
	try
	{
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;
		b1.incGrade();
		std::cout << "Apres incGrade: " << b1 << std::endl;
		b1.decGrade();
		std::cout << "Apres decGrade: " << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test GradeTooHighException (constructeur) ---" << std::endl;
	try
	{
		Bureaucrat b2("Bob", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test GradeTooLowException (constructeur) ---" << std::endl;
	try
	{
		Bureaucrat b3("Charlie", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test GradeTooHighException (incGrade) ---" << std::endl;
	try
	{
		Bureaucrat b4("Dave", 2);
		b4.incGrade();
		b4.incGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test GradeTooLowException (decGrade) ---" << std::endl;
	try
	{
		Bureaucrat b5("Eve", 149);
		b5.decGrade();
		b5.decGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
