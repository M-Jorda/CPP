/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:35:52 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/22 18:39:21 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap")
{
	std::cout << "Creation of standard ScavTrap ..." << std::endl;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDmg = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Creation of ScavTrap " << name << std::endl;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other._name)
{
	std::cout << "Creation of a copy of " << other._name << std::endl;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDmg = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destruction of " << _name << std::endl;
}


ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
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

void		ScavTrap::attack(const std::string& target)
{
	if (_energyPoint > 0)
	{
		std::cout << "ScavTrap " << _name << " attack " << target;
		std::cout << ", causing " << _attackDmg << " points of damage !" << std::endl;
		_energyPoint -= 1;
	}
	else
		std::cout << "ScavTrap " << _name <<" doesn't have enought energy to attack." << std::endl;
}

void 		ScavTrap::guardGate()
{
	if (_energyPoint > 0){
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
		_energyPoint -= 1;
	}
	else
		std::cout << "ScavTrap " << _name <<" doesn't have enought energy to attack." << std::endl;
}

