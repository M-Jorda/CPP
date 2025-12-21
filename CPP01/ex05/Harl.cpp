/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:10:46 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/20 17:41:03 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << DEBUG << std::endl;
}

void	Harl::info()
{
	std::cout << INFO << std::endl;
}

void	Harl::warning()
{
	std::cout << WARNING << std::endl;
}

void	Harl::error()
{
	std::cout << ERROR << std::endl;
}

void	Harl::complain(std::string level)
{
	typedef void	(Harl::*funcPtr)(void);

	struct	complaintLevel {
		std::string	name;
		funcPtr		func;
	};

	complaintLevel complaints[4] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	for (int i = 0; i < 4; i++)
	{
		if (complaints[i].name == level)
		{
			(this->*complaints[i].func)();
			return ;
		}
	}

	std::cout << "invalid level: " << level << std::endl;
}
