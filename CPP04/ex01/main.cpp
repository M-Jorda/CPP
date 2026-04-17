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
	cout << "=== Array of Animals (5 Dogs, 5 Cats) ===" << endl;
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

	cout << endl << "=== Deep copy test (Dog copy constructor) ===" << endl;
	{
		Dog	dog1;
		dog1.getBrain()->setIdea(0, "chase cats");
		dog1.getBrain()->setIdea(1, "eat food");

		Dog	dog2(dog1);
		cout << "dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << endl;
		cout << "dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << endl;

		dog2.getBrain()->setIdea(0, "sleep all day");
		cout << "After modifying dog2:" << endl;
		cout << "dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << endl;
		cout << "dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << endl;
	}

	cout << endl << "=== Deep copy test (Cat assignment operator) ===" << endl;
	{
		Cat	cat1;
		cat1.getBrain()->setIdea(0, "knock things off tables");

		Cat	cat2;
		cat2 = cat1;
		cout << "cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << endl;
		cout << "cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << endl;

		cat2.getBrain()->setIdea(0, "sleep");
		cout << "After modifying cat2:" << endl;
		cout << "cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << endl;
		cout << "cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << endl;
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
