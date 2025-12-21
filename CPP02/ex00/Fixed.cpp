/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:34:53 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/21 11:50:26 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << DEFAULT << std::endl;
	_rawBits = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << COPY << std::endl;
	_rawBits = other._rawBits;
}

Fixed::~Fixed(void)
{
	std::cout << DESTRUCTOR << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		_rawBits = other._rawBits;
		std::cout << ASSIGN << std::endl;
	}
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << GETRAW << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}
