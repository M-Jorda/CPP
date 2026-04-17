/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:22:44 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 14:22:44 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	cout << NAME_BRAIN << MSG_DF_CONS << endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	cout << NAME_BRAIN << MSG_CP_CONS << endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	return *this;
}

Brain::~Brain()
{
	cout << NAME_BRAIN << MSG_DES << endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	return "";
}
