/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:43:38 by jjorda            #+#    #+#             */
/*   Updated: 2026/04/16 21:51:44 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include	"FragTrap.hpp"
# include	"ScavTrap.hpp"

# define	ATTACKDMG	30

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
		std::string	getName(void) const;
		int			getHitPoint(void) const;
		int			getEnergyPoint(void) const;
		int			getAttackDmg(void) const;
};

#endif
