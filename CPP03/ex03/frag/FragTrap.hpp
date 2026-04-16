/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:13:41 by jjorda            #+#    #+#             */
/*   Updated: 2026/04/16 21:48:52 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public :
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap &other);
		virtual	~FragTrap(void);

		FragTrap	&operator=(const FragTrap &other);
		void		highFivesGuys(void);
};

#endif
