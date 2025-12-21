/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 10:55:27 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/20 12:39:39 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	_name = "";
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::Zombie(const Zombie &other)
{
	_name = other._name;
}

Zombie::~Zombie()
{
	std::cout << "destructor called for " << _name << std::endl;
}

Zombie	&Zombie::operator=(const Zombie &other)
{
	if (this != &other)
		_name = other._name;
	return (*this);
}

void	Zombie::announce(void)
{
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}
