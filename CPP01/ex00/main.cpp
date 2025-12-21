/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 10:55:40 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/20 11:52:58 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie zombie_1 = Zombie("Foo");
	Zombie zombie_2 = Zombie(zombie_1);
	
	Zombie *zombie_3 = newZombie("Bar");
	randomChump("Baz");
	delete(zombie_3);
}
