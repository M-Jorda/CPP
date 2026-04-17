/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:39:54 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 12:39:54 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// Animal a; // Does not compile: Animal is abstract

	cout << "=== Abstract class: only Dog and Cat can be instantiated ===" << endl;
	{
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		cout << j->getType() << endl;
		cout << i->getType() << endl;
		j->makeSound();
		i->makeSound();

		delete j;
		delete i;
	}

	cout << endl << "=== Array of Animals (5 Dogs, 5 Cats) ===" << endl;
	{
		const int	size = 10;
		Animal*		animals[size];

		for (int i = 0; i < size / 2; i++)
			animals[i] = new Dog();
		for (int i = size / 2; i < size; i++)
			animals[i] = new Cat();

		cout << endl << "--- Sounds ---" << endl;
		for (int i = 0; i < size; i++)
			animals[i]->makeSound();

		cout << endl << "--- Deleting all ---" << endl;
		for (int i = 0; i < size; i++)
			delete animals[i];
	}

	cout << endl << "=== Deep copy test ===" << endl;
	{
		Dog	dog1;
		dog1.getBrain()->setIdea(0, "chase cats");

		Dog	dog2(dog1);
		dog2.getBrain()->setIdea(0, "sleep all day");

		cout << "dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << endl;
		cout << "dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << endl;
	}

	cout << endl << "=== WrongAnimal (no virtual) ===" << endl;
	{
		const WrongAnimal*	wa = new WrongCat();
		cout << wa->getType() << endl;
		wa->makeSound();
		delete wa;
	}

	return 0;
}
