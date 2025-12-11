/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Example.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:00:00 by                   #+#    #+#             */
/*   Updated: 2025/12/11 06:25:17 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <string>
#include <iostream>

// Exemple : une classe Livre
class Livre
{
private:
	// Attributs PRIVÉS (utilisés seulement dans la classe)
	std::string	_title;
	std::string	_author;
	int			_pages;

public:
	// Constructeur
	Livre(void);
	
	// Destructeur
	~Livre(void);

	// Getters (méthodes publiques pour accéder aux données privées)
	std::string	getTitle(void) const;
	std::string	getAuthor(void) const;
	int			getPages(void) const;

	// Setters (méthodes publiques pour modifier les données privées)
	void		setTitle(std::string title);
	void		setAuthor(std::string author);
	void		setPages(int pages);

	// Autre méthode publique
	void		displayInfo(void) const;
};

#endif
