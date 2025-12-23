/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:43:38 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 10:04:17 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "DiamondTrap.h"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private :
		std::string	_name;

	public :
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap(void);

		DiamondTrap	&operator=(const DiamondTrap &other);
		void		attack(const std::string &target);
		void		whoAmI();
};

#endif
