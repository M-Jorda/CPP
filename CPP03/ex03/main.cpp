/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 08:51:15 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 10:15:19 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "===== TEST 1 : DiamondTrap Default Constructor =====" << std::endl;
	DiamondTrap diamond1;
	
	std::cout << "\n===== TEST 2 : DiamondTrap Constructor with name =====" << std::endl;
	DiamondTrap diamond2("Diamond");
	
	std::cout << "\n===== TEST 3 : DiamondTrap Copy Constructor =====" << std::endl;
	DiamondTrap diamond3(diamond2);
	
	std::cout << "\n===== TEST 4 : DiamondTrap Assignment Operator =====" << std::endl;
	DiamondTrap diamond4;
	diamond4 = diamond2;
	
	std::cout << "\n===== TEST 5 : DiamondTrap Attack (ScavTrap) =====" << std::endl;
	diamond2.attack("Enemy");
	
	std::cout << "\n===== TEST 6 : DiamondTrap Take Damage =====" << std::endl;
	diamond1.takeDamage(15);
	
	std::cout << "\n===== TEST 7 : DiamondTrap Be Repaired =====" << std::endl;
	diamond1.beRepaired(10);
	
	std::cout << "\n===== TEST 8 : DiamondTrap Multiple Attacks =====" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		diamond2.attack("Enemy");
		diamond1.takeDamage(10);
	}
	
	std::cout << "\n===== TEST 9 : DiamondTrap Repair after damage =====" << std::endl;
	diamond1.beRepaired(25);
	
	std::cout << "\n===== TEST 10 : DiamondTrap Energy depletion =====" << std::endl;
	for (int i = 0; i < 50; i++)
	{
		if (i % 20 == 0)
			std::cout << "Attack attempt " << (i + 1) << ":" << std::endl;
		diamond2.attack("Enemy");
	}
	
	std::cout << "\n===== TEST 11 : DiamondTrap whoAmI() =====" << std::endl;
	diamond2.whoAmI();
	
	std::cout << "\n===== TEST 12 : DiamondTrap Attributes =====" << std::endl;
	std::cout << "DiamondTrap has:" << std::endl;
	std::cout << "  - Hit Points: 100 (from FragTrap)" << std::endl;
	std::cout << "  - Energy Points: 50 (from ScavTrap)" << std::endl;
	std::cout << "  - Attack Damage: 30 (from FragTrap)" << std::endl;
	
	std::cout << "\n===== TEST 13 : DiamondTrap whoAmI() multiple times =====" << std::endl;
	for (int i = 0; i < 2; i++)
	{
		std::cout << "whoAmI() call " << (i + 1) << ":" << std::endl;
		diamond1.whoAmI();
	}
	
	std::cout << "\n===== TEST 14 : DiamondTrap inheritance - all inherited methods =====" << std::endl;
	std::cout << "DiamondTrap can use inherited methods:" << std::endl;
	std::cout << "  - attack() (from ScavTrap)" << std::endl;
	std::cout << "  - takeDamage() (from ClapTrap)" << std::endl;
	std::cout << "  - beRepaired() (from ClapTrap)" << std::endl;
	diamond1.attack("Enemy");
	diamond1.takeDamage(20);
	diamond1.beRepaired(15);
	
	std::cout << "\n===== TEST 15 : Destructors =====" << std::endl;
	std::cout << "All DiamondTrap objects being destroyed..." << std::endl;
	
	return 0;
}
