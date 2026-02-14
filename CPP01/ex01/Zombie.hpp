/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 10:54:24 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/20 12:39:39 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "Zombie.h"

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(void);
		Zombie(std::string name);
		Zombie(const Zombie &other);
		~Zombie();
		
		Zombie	&operator=(const Zombie &other);
		void	announce(void);
		void	setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
