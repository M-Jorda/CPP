/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:18:09 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/20 12:20:02 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N = 4;

	Zombie *horde = zombieHorde(N, "Foo");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}
