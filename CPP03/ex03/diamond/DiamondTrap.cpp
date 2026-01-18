/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:53:19 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 10:10:36 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	: ClapTrap("DiamondTrap_clap_name"), FragTrap("DiamondTrap_clap_name"),
	ScavTrap("DiamondTrap_clap_name")
{
	std::cout << "Creation of standard DiamondTrap ..." << std::endl;
	_name = "DiamondTrap";
	_hitPoint = FragTrap::_hitPoint;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDmg = FragTrap::_attackDmg;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"), _name(name)
{
	std::cout << "Creation of DiamondTrap " << name << std::endl;
	_hitPoint = FragTrap::_hitPoint;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDmg = FragTrap::_attackDmg;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other),  _name(other._name)
{
	std::cout << "Creation of a copy of " << other._name << std::endl;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDmg = other._attackDmg;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destruction of " << _name << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		std::cout << "Creation by assignation of a copy of " << other._name << std::endl;
		this->_name = other._name;
		this->_hitPoint = other._hitPoint;
		this->_energyPoint = other._energyPoint;
		this->_attackDmg = other._attackDmg;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
		ScavTrap::attack(target);
}

void		DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is: " << _name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}
