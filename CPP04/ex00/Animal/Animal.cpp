/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:47:48 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 11:55:16 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("animal")
{
	std::cout << "Standard Animal create" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal create. Type : " << _type << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy from " << other._type << std::endl;
	this->_type = other._type;
}

Animal::~Animal(void)
{
	std::cout << "Hunter came ..." << std::endl;
}

Animal 			&Animal::operator=(const Animal &other)
{
	
}

void	Animal::makeSound()
{
	
}

std::string		Animal::getType(void)
{
	
}
