/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Example.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:00:00 by                   #+#    #+#             */
/*   Updated: 2025/12/11 06:25:17 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Example.hpp"

// Constructeur : initialise les attributs
Livre::Livre(void) : _title(""), _author(""), _pages(0)
{
	std::cout << "Livre créé" << std::endl;
}

// Destructeur : nettoie quand l'objet est supprimé
Livre::~Livre(void)
{
	std::cout << "Livre supprimé" << std::endl;
}

// Getter pour le titre
std::string	Livre::getTitle(void) const
{
	return (_title);
}

// Getter pour l'auteur
std::string	Livre::getAuthor(void) const
{
	return (_author);
}

// Getter pour les pages
int	Livre::getPages(void) const
{
	return (_pages);
}

// Setter pour le titre
void	Livre::setTitle(std::string title)
{
	_title = title;
}

// Setter pour l'auteur
void	Livre::setAuthor(std::string author)
{
	_author = author;
}

// Setter pour les pages
void	Livre::setPages(int pages)
{
	if (pages > 0)
		_pages = pages;
}

// Affiche les infos du livre
void	Livre::displayInfo(void) const
{
	std::cout << "Titre: " << _title << std::endl;
	std::cout << "Auteur: " << _author << std::endl;
	std::cout << "Pages: " << _pages << std::endl;
}
