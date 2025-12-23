/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 08:51:15 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 10:50:00 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	std::cout << "===== TEST 1 : Default Constructor =====" << std::endl;
	FragTrap frag1;
	
	std::cout << "\n===== TEST 2 : Constructor with name =====" << std::endl;
	FragTrap frag2("Robot");
	
	std::cout << "\n===== TEST 3 : Copy Constructor =====" << std::endl;
	FragTrap frag3(frag2);
	
	std::cout << "\n===== TEST 4 : Assignment Operator =====" << std::endl;
	FragTrap frag4;
	frag4 = frag2;
	
	std::cout << "\n===== TEST 5 : Inherited - Attack =====" << std::endl;
	frag2.attack("Enemy");
	
	std::cout << "\n===== TEST 6 : Inherited - Take Damage =====" << std::endl;
	frag1.takeDamage(15);
	
	std::cout << "\n===== TEST 7 : Inherited - Be Repaired =====" << std::endl;
	frag1.beRepaired(10);
	
	std::cout << "\n===== TEST 8 : Inherited - Multiple Attacks =====" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		frag2.attack("Enemy");
		frag1.takeDamage(10);
	}
	
	std::cout << "\n===== TEST 9 : Inherited - Repair after damage =====" << std::endl;
	frag1.beRepaired(25);
	
	std::cout << "\n===== TEST 10 : Inherited - Energy depletion =====" << std::endl;
	for (int i = 0; i < 50; i++)
	{
		if (i % 20 == 0)
			std::cout << "Attack attempt " << (i + 1) << ":" << std::endl;
		frag2.attack("Enemy");
	}
	
	std::cout << "\n===== TEST 11 : FragTrap specific method - highFivesGuys() =====" << std::endl;
	frag2.highFivesGuys();
	
	std::cout << "\n===== TEST 12 : FragTrap vs ClapTrap stats =====" << std::endl;
	std::cout << "FragTrap has:" << std::endl;
	std::cout << "  - Hit Points: 100 (vs ClapTrap 10)" << std::endl;
	std::cout << "  - Energy Points: 100 (vs ClapTrap 10)" << std::endl;
	std::cout << "  - Attack Damage: 30 (vs ClapTrap 0)" << std::endl;
	
	std::cout << "\n===== TEST 13 : Multiple highFivesGuys calls =====" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "High-five call " << (i + 1) << ":" << std::endl;
		frag1.highFivesGuys();
	}
	
	std::cout << "\n===== TEST 14 : FragTrap inheritance - all inherited methods =====" << std::endl;
	std::cout << "FragTrap can use inherited ClapTrap methods:" << std::endl;
	std::cout << "  - attack()" << std::endl;
	std::cout << "  - takeDamage()" << std::endl;
	std::cout << "  - beRepaired()" << std::endl;
	frag1.attack("Enemy");
	frag1.takeDamage(20);
	frag1.beRepaired(15);
	
	std::cout << "\n===== TEST 15 : Destructors =====" << std::endl;
	std::cout << "All FragTrap objects being destroyed..." << std::endl;
	
	return 0;
}
