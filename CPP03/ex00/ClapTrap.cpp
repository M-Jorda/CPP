/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:50:00 by jjorda            #+#    #+#             */
/*   Updated: 2026/04/16 18:22:37 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("clap_trap"), _hitPoint(10), _energyPoint(10), _attackDmg(0)
{
	std::cout << "Creation of standard Claptrap ..." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hitPoint(10), _energyPoint(10), _attackDmg(0)
{
	std::cout << "Creation of Claptrap " << name << std::endl;
	_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	_name = other._name;
	_hitPoint = other._hitPoint;
	_energyPoint = other._energyPoint;
	_attackDmg = other._attackDmg;
	std::cout << "Creation of a copy of " << _name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destruction of " << _name << std::endl;
}


ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
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

void		ClapTrap::attack(const std::string& target)
{
	if (_hitPoint <= 0)
	{
		std::cout << "This Claptrap doesn't exist anymore" << std::endl;
		return ;
	}
	if (_energyPoint > 0){
		std::cout << "Claptrap " << _name << " attack " << target;
		std::cout << ", causing " << _attackDmg << " points of damage !" << std::endl;
		_energyPoint--;
	}
	else
		std::cout << "Claptrap " << _name <<" doesn't have enough energy to attack." << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoint > 0)
	{
		std::cout << "Claptrap " << _name << " being attack, causing ";
		std::cout << amount << " of damage !" << std::endl;
		_hitPoint -= amount;
		if (_hitPoint <= 0)
			std::cout << "Claptrap " << _name << " doesn't have enough hit point to continue" << std::endl;
	}
	else
		std::cout << "This Claptrap doesn't exist anymore" << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoint <= 0)
	{
		std::cout << "This Claptrap doesn't exist anymore" << std::endl;
		return ;
	}
	if (_energyPoint > 0)
	{
		_hitPoint += amount;
		_energyPoint--;
		std::cout << "Claptrap " << _name << " repair itself, regaining ";
		std::cout << amount << " of hit points." << std::endl;
	}
	else
		std::cout << "Claptrap " << _name << " doesn't have enough energy ..." << std::endl;
}

