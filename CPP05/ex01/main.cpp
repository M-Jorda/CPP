/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:07:05 by jjorda            #+#    #+#             */
/*   Updated: 2026/05/18 18:39:38 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

int	main(void)
{
	Bureaucrat John("John", 75);
	cout << John.getName() << ": " << John.getGrade() << endl;
	try
	{
		for (int i = 0; i < 100; i++)
			John.decGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	cout << John << endl;
}
