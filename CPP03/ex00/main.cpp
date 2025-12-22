/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 08:51:15 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/22 09:04:43 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "===== TEST 1 : Default Constructor =====" << std::endl;
	ClapTrap clap1;
	
	std::cout << "\n===== TEST 2 : Constructor with name =====" << std::endl;
	ClapTrap clap2("Robot");
	
	std::cout << "\n===== TEST 3 : Copy Constructor =====" << std::endl;
	ClapTrap clap3(clap2);
	
	std::cout << "\n===== TEST 4 : Assignment Operator =====" << std::endl;
	ClapTrap clap4;
	clap4 = clap2;
	
	std::cout << "\n===== TEST 5 : Attack =====" << std::endl;
	clap2.attack("Clap1");
	
	std::cout << "\n===== TEST 6 : Take Damage =====" << std::endl;
	clap1.takeDamage(5);
	
	std::cout << "\n===== TEST 7 : Be Repaired =====" << std::endl;
	clap1.beRepaired(3);
	
	std::cout << "\n===== TEST 8 : Multiple Attacks =====" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		clap2.attack("Clap1");
		clap1.takeDamage(3);
	}
	
	std::cout << "\n===== TEST 9 : Repair after damage =====" << std::endl;
	clap1.beRepaired(8);
	
	std::cout << "\n===== TEST 10 : Energy depletion =====" << std::endl;
	for (int i = 0; i < 15; i++)
	{
		std::cout << "Attack attempt " << (i + 1) << ":" << std::endl;
		clap2.attack("Clap1");
	}
	
	std::cout << "\n===== TEST 11 : Destructors =====" << std::endl;
	
	return 0;
}
