/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:54:32 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 13:54:32 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include "Polymorphism.hpp"

# define NAME_WRONGANIMAL	"WrongAnimal"
# define MSG_WRONGANIMAL	"WrongAnimal sound..."

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal&	operator=(const WrongAnimal& other);
		~WrongAnimal();

		void		makeSound() const;
		std::string	getType() const;
};

std::ostream& operator<<(std::ostream& os, const WrongAnimal& other);
