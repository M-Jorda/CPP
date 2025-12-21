/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:34:13 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/21 11:14:33 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << DEBUG << std::endl;
}

void	Harl::info(void)
{
	std::cout << INFO << std::endl;
}

void	Harl::warning(void)
{
	std::cout << WARNING << std::endl;
}

void	Harl::error(void)
{
	std::cout << ERROR << std::endl;
}

static inline int	getLevel(std::string level)
{
	s_complainLevel complaints[4] = {
		{"DEBUG", 0},
		{"INFO", 1},
		{"WARNING", 2},
		{"ERROR", 3}
	};

	for (int i = 0; i < 4; i++)
		if (complaints[i].name == level)
			return (complaints[i].level);
	return (-1);
}

void	Harl::complain(std::string complain)
{
	int	level = getLevel(complain);
	switch (level)
	{
		case 0:
			debug();
			// fall through
		case 1:
			info();
			// fall through
		case 2:
			warning();
			// fall through
		case 3:
			error();
			break ;
		default:
			std::cout << COMPLAIN << std::endl;
	}
}
