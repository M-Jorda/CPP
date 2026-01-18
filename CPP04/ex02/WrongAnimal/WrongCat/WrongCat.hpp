/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:03:52 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 14:04:41 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongCat.h"

class WrongCat : public WrongAnimal
{
	private :
		std::string	_name;

	public :
		WrongCat(void);
		WrongCat(std::string name);
		WrongCat(const WrongCat &other);
		~WrongCat(void);

		WrongCat	&operator=(const WrongCat &other);
		void		makeSound()							const;
};

#endif