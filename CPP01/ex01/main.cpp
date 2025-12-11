/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:00:00 by                   #+#    #+#             */
/*   Updated: 2025/12/11 06:25:17 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Example.hpp"

int	main(void)
{
	// Créer un objet Livre (appelle le constructeur)
	Livre myBook;

	// Utiliser les setters pour remplir les données
	myBook.setTitle("1984");
	myBook.setAuthor("George Orwell");
	myBook.setPages(328);

	// Afficher les infos
	myBook.displayInfo();

	// Accéder aux données via les getters
	std::cout << "\nLe livre s'appelle: " << myBook.getTitle() << std::endl;

	return (0);
}
