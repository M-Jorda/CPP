/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:38:14 by jjorda            #+#    #+#             */
/*   Updated: 2026/04/17 20:36:42 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include "Polymorphism.hpp"

# define NAME_ANIMAL	"Animal"
# define MSG_ANIMAL		"..."

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(const Animal& other);
		Animal&			operator=(const Animal& other);
		virtual			~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;
};

std::ostream& operator<<(std::ostream& os, const Animal& other);