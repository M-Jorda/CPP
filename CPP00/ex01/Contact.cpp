/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 06:35:56 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/18 18:18:28 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//                                  (DE)CONST

Contact::Contact(void) : _firstName(""), _lastName(""), _nickName(""),
	_darkestSecret(""), _number(0L)
{
	// std::cout << "Contact created" << std::endl;
}

Contact::~Contact(void)
{
	// std::cout << "Contact replaced" << std::endl;
}

//                                   GETTER

std::string Contact::getFirstName(void) const
{
	return (_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (_lastName);
}

std::string	Contact::getNickName(void) const
{
	return (_nickName);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}

long	Contact::getNumber(void) const
{
	return (_number);
}

//                                   SETTER

void	Contact::setFirstName(std::string firstName)
{
	_firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	_lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	_nickName = nickName;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	_darkestSecret = darkestSecret;
}

void	Contact::setNumber(long number)
{
	_number = number;
}
