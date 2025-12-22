/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:50:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/22 08:25:02 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("clap_trap"), _hitPoint(10), _energyPoint(10), _attackDmg(0)
{}

ClapTrap::ClapTrap(std::string name) : _hitPoint(10), _energyPoint(10), _attackDmg(0)
{
	_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _hitPoint(10), _energyPoint(10), _attackDmg(0)
{
	_name = other._name;
}

ClapTrap::~ClapTrap(void)
{}


ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	if (this != other)
	{
		
	}
}

void		ClapTrap::attack(const std::string& target)
{
	
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	
}

