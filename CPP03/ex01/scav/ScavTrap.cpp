/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:35:52 by jjorda            #+#    #+#             */
/*   Updated: 2026/04/16 21:35:22 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "Creation of standard ScavTrap ..." << std::endl;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDmg = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDmg = 20;
	std::cout << "Creation of ScavTrap " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Creation of a copy of " << _name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destruction of " << _name << std::endl;
}


ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoint = other._hitPoint;
		_energyPoint = other._energyPoint;
		_attackDmg = other._attackDmg;
		std::cout << "Creation by assignation of a copy of " << _name << std::endl;
	}
	return (*this);
}

void		ScavTrap::attack(const std::string& target)
{
	if (_hitPoint <= 0)
	{
		std::cout << "This ScavTrap doesn't exist anymore" << std::endl;
		return ;
	}
	if (_energyPoint > 0)
	{
		std::cout << "ScavTrap " << _name << " attack " << target;
		std::cout << ", causing " << _attackDmg << " points of damage !" << std::endl;
		_energyPoint -= 1;
	}
	else
		std::cout << "ScavTrap " << _name <<" doesn't have enough energy to attack." << std::endl;
}

void 		ScavTrap::guardGate()
{
	if (_hitPoint <= 0)
	{
		std::cout << "This ScavTrap doesn't exist anymore" << std::endl;
		return ;
	}
	if (_energyPoint > 0){
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
		_energyPoint -= 1;
	}
	else
		std::cout << "ScavTrap " << _name <<" doesn't have enough energy to keep the gate." << std::endl;
}

