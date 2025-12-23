/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:18:44 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 08:31:19 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("FragTrap")
{
	std::cout << "Creation of standard FragTrap ..." << std::endl;
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDmg = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "Creation of FragTrap ..." << std::endl;
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDmg = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other._name)
{
	std::cout << "Creation of a copy of " << other._name << std::endl;
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDmg = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destruction of " << _name << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		std::cout << "Creation by assignation of a copy of " << other._name << std::endl;
		_name = other._name;
		_hitPoint = other._hitPoint;
		_energyPoint = other._energyPoint;
		_attackDmg = other._attackDmg;
	}
	return (*this);
}

void		FragTrap::highFivesGuys(void)
{
	if (_energyPoint > 0){
		std::cout << "FragTrap " << _name << " is doing an amazing and positive high-fives." << std::endl;
		_energyPoint -= 1;
	}
	else
		std::cout << "FragTrap " << _name <<" doesn't have enought energy to high-fives." << std::endl;
}
