/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:54:32 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 13:59:24 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "WrongAnimal.h"

class WrongAnimal
{
	protected :
		std::string	_type;

	public :
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &other);
		~WrongAnimal(void);

		WrongAnimal	&operator=(const WrongAnimal &other);
		void		makeSound(void)							const;
		std::string	getType(void)							const;
};

#endif
