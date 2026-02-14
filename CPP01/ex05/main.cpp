/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:20:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/20 17:30:00 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	std::cout << "=== Testing Harl complains ===" << std::endl;
	std::cout << std::endl;

	std::cout << "--- Testing DEBUG level ---" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "--- Testing INFO level ---" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "--- Testing WARNING level ---" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "--- Testing ERROR level ---" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "--- Testing invalid level ---" << std::endl;
	harl.complain("INVALID");
	std::cout << std::endl;

	std::cout << "--- Testing lowercase (should fail) ---" << std::endl;
	harl.complain("debug");
	std::cout << std::endl;

	return (0);
}
