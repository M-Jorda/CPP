/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:22:44 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 15:24:09 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "A new brain grew up ..." << std::endl;
	_CountIdea = 0;
}

Brain::Brain(std::string idea)
{
	_ideas[0] = idea;
	_CountIdea = 1;
	std::cout << "A new brain grew up with it first idea : " << idea << std::endl;
}

Brain::Brain(const Brain &other)
{
	_CountIdea = other._CountIdea;
	for (int i = 0; i < _CountIdea; i++)
		_ideas[i] = other._ideas[i];
	std::cout << "A new brain grew up with " << _CountIdea << " idea(s)" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "The Brain destructor called" << std::endl;
}

Brain		&Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		_CountIdea = other._CountIdea;
		for (int i = 0; i < _CountIdea; i++)
			_ideas[i] = other._ideas[i];
		std::cout << "A new brain has been assigned with " << _CountIdea << " idea(s)" << std::endl;
	}
	return (*this);
}

void	Brain::setideas(std::string *ideas, int countIdea)
{
	if (_CountIdea > 99)
	{
		std::cout << "The number max of ideas already reach" << std::endl;
		return ;
	}
	for (int i = _CountIdea; i < 100; i++)
		_ideas[i] = ideas[countIdea];
	std::cout << "A new set of ideas reach the brain" << std::endl;
}

void	Brain::setIdea(std::string idea)
{
	if (_CountIdea > 99)
	{
		std::cout << "The number max of ideas already reach" << std::endl;
		return ;
	}
	_ideas[_CountIdea] = idea;
	_CountIdea++;
	std::cout << "A new idea reach the brain" << std::endl;
}

std::string	Brain::getIdea(int idea)
{
	return (_ideas[idea]);
}

std::string	*Brain::getIdeas(void)
{
	return (_ideas);
}
