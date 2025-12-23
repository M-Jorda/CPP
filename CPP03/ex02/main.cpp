/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 08:51:15 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/22 18:34:09 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "===== TEST 1 : Default Constructor =====" << std::endl;
	ScavTrap clap1;
	
	std::cout << "\n===== TEST 2 : Constructor with name =====" << std::endl;
	ScavTrap clap2("Robot");
	
	std::cout << "\n===== TEST 3 : Copy Constructor =====" << std::endl;
	ScavTrap clap3(clap2);
	
	std::cout << "\n===== TEST 4 : Assignment Operator =====" << std::endl;
	ScavTrap clap4;
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
	
	std::cout << "\n===== TEST 11 : ScavTrap specific method - guardGate() =====" << std::endl;
	clap2.guardGate();
	
	std::cout << "\n===== TEST 12 : ScavTrap vs ClapTrap stats =====" << std::endl;
	std::cout << "ScavTrap has:" << std::endl;
	std::cout << "  - Hit Points: 100 (vs ClapTrap 10)" << std::endl;
	std::cout << "  - Energy Points: 50 (vs ClapTrap 10)" << std::endl;
	std::cout << "  - Attack Damage: 20 (vs ClapTrap 0)" << std::endl;
	
	std::cout << "\n===== TEST 13 : Multiple guardGate calls =====" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Guard Gate call " << (i + 1) << ":" << std::endl;
		clap1.guardGate();
	}
	
	std::cout << "\n===== TEST 14 : ScavTrap inheritance - inherited methods =====" << std::endl;
	std::cout << "ScavTrap can use inherited ClapTrap methods:" << std::endl;
	std::cout << "  - attack()" << std::endl;
	std::cout << "  - takeDamage()" << std::endl;
	std::cout << "  - beRepaired()" << std::endl;
	clap1.attack("Enemy");
	clap1.takeDamage(10);
	clap1.beRepaired(5);
	
	std::cout << "\n===== TEST 15 : Destructors =====" << std::endl;
	std::cout << "All ScavTrap objects being destroyed..." << std::endl;
	
	return 0;
}
