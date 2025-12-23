/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 08:51:15 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 11:07:35 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "===== TEST 1 : Default Constructor =====" << std::endl;
	ScavTrap scav1;
	
	std::cout << "\n===== TEST 2 : Constructor with name =====" << std::endl;
	ScavTrap scav2("Robot");
	
	std::cout << "\n===== TEST 3 : Copy Constructor =====" << std::endl;
	ScavTrap scav3(scav2);
	
	std::cout << "\n===== TEST 4 : Assignment Operator =====" << std::endl;
	ScavTrap scav4;
	scav4 = scav2;
	
	std::cout << "\n===== TEST 5 : ScavTrap Attack (different message) =====" << std::endl;
	scav2.attack("Enemy");
	
	std::cout << "\n===== TEST 6 : Inherited - Take Damage =====" << std::endl;
	scav1.takeDamage(15);
	
	std::cout << "\n===== TEST 7 : Inherited - Be Repaired =====" << std::endl;
	scav1.beRepaired(10);
	
	std::cout << "\n===== TEST 8 : Inherited - Multiple Attacks =====" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		scav2.attack("Enemy");
		scav1.takeDamage(10);
	}
	
	std::cout << "\n===== TEST 9 : Inherited - Repair after damage =====" << std::endl;
	scav1.beRepaired(25);
	
	std::cout << "\n===== TEST 10 : Inherited - Energy depletion =====" << std::endl;
	for (int i = 0; i < 50; i++)
	{
		if (i % 20 == 0)
			std::cout << "Attack attempt " << (i + 1) << ":" << std::endl;
		scav2.attack("Enemy");
	}
	
	std::cout << "\n===== TEST 11 : ScavTrap specific method - guardGate() =====" << std::endl;
	scav2.guardGate();
	
	std::cout << "\n===== TEST 12 : ScavTrap vs ClapTrap stats =====" << std::endl;
	std::cout << "ScavTrap has:" << std::endl;
	std::cout << "  - Hit Points: 100 (vs ClapTrap 10)" << std::endl;
	std::cout << "  - Energy Points: 50 (vs ClapTrap 10)" << std::endl;
	std::cout << "  - Attack Damage: 20 (vs ClapTrap 0)" << std::endl;
	
	std::cout << "\n===== TEST 13 : Multiple guardGate calls =====" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Guard Gate call " << (i + 1) << ":" << std::endl;
		scav1.guardGate();
	}
	
	std::cout << "\n===== TEST 14 : ScavTrap inheritance - all inherited methods =====" << std::endl;
	std::cout << "ScavTrap can use inherited ClapTrap methods:" << std::endl;
	std::cout << "  - attack() (overridden)" << std::endl;
	std::cout << "  - takeDamage() (inherited)" << std::endl;
	std::cout << "  - beRepaired() (inherited)" << std::endl;
	scav1.attack("Enemy");
	scav1.takeDamage(20);
	scav1.beRepaired(15);
	
	std::cout << "\n===== TEST 15 : Destructors =====" << std::endl;
	std::cout << "All ScavTrap objects being destroyed..." << std::endl;
	
	return 0;
}
