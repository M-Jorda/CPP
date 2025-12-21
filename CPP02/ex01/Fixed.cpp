/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:34:53 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/21 12:57:05 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << DEFAULT << std::endl;
	_rawBits = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << INT << std::endl;
	_rawBits = num * (1 << _fractionalBits);
}

Fixed::Fixed(const float num)
{
	std::cout << FLOAT << std::endl;
	_rawBits = roundf(num * (1 << _fractionalBits));
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
	std::cout << ASSIGN << std::endl;
	if (this != &other)
		_rawBits = other._rawBits;
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

float	Fixed::toFloat(void) const
{
	return ((float) _rawBits / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (_rawBits / (1 << _fractionalBits));
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
