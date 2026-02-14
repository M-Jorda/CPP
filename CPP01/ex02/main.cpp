/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:45:03 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/20 13:45:51 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
# include <iostream>

int	main(void)
{
	std::string string =  "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Adress string:		" << &string << std::endl;
	std::cout << "Adress stringPTR:	" << stringPTR << std::endl;
	std::cout << "Adress stringREF:	" << &stringREF << std::endl;
	
	std::cout << "\nValue string:		" << string << std::endl;
	std::cout << "Value stringPTR:	" << *stringPTR << std::endl;
	std::cout << "Value stringREF:	" << stringREF << std::endl;
}
