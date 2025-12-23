/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:39:54 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 16:45:38 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal/Animal.hpp"
#include "Animal/Dog/Dog.hpp"
#include "Animal/Cat/Cat.hpp"

int main()
{
	std::cout << "=== TEST 1: Abstract class - Cannot instantiate Animal ===" << std::endl;
	std::cout << "Trying to create: Animal a;" << std::endl;
	std::cout << "Result: COMPILATION ERROR - Animal is abstract!" << std::endl;
	std::cout << "        (Animal has pure virtual method: makeSound() = 0)" << std::endl;
	// Animal a;  // ❌ WOULD NOT COMPILE

	std::cout << std::endl << "=== TEST 2: Can only instantiate concrete classes ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl << "--- Types and sounds ---" << std::endl;
	std::cout << j->getType() << " ";
	j->makeSound();
	std::cout << i->getType() << " ";
	i->makeSound();
	
	std::cout << std::endl << "--- Cleanup ---" << std::endl;
	delete j; // should not create a leak
	delete i;

	std::cout << std::endl << "=== TEST 3: Array of Animals (half Dogs, half Cats) ===" << std::endl;
	const int arraySize = 10;
	Animal* animals[arraySize];

	std::cout << std::endl << "--- Creating Dogs ---" << std::endl;
	for (int idx = 0; idx < arraySize / 2; idx++)
		animals[idx] = new Dog();

	std::cout << std::endl << "--- Creating Cats ---" << std::endl;
	for (int idx = arraySize / 2; idx < arraySize; idx++)
		animals[idx] = new Cat();

	std::cout << std::endl << "--- Making sounds (polymorphism through abstract class) ---" << std::endl;
	for (int idx = 0; idx < arraySize; idx++)
	{
		std::cout << animals[idx]->getType() << ": ";
		animals[idx]->makeSound();
	}

	std::cout << std::endl << "--- Deleting all Animals ---" << std::endl;
	for (int idx = 0; idx < arraySize; idx++)
		delete animals[idx];

	std::cout << std::endl << "=== TEST 4: Deep copy test (Copy constructor) ===" << std::endl;
	{
		Dog originalDog;
		std::cout << std::endl << "--- Creating copy ---" << std::endl;
		Dog copyDog = originalDog;
		
		std::cout << std::endl << "--- Both dogs making sound ---" << std::endl;
		originalDog.makeSound();
		copyDog.makeSound();
		
		std::cout << std::endl << "--- Destructors (leaving scope) ---" << std::endl;
	}

	std::cout << std::endl << "=== TEST 5: Deep copy test (Assignment operator) ===" << std::endl;
	{
		Dog dog1;
		Dog dog2;
		
		std::cout << std::endl << "--- Assignment operator ---" << std::endl;
		dog2 = dog1;
		
		std::cout << std::endl << "--- Both dogs making sound ---" << std::endl;
		dog1.makeSound();
		dog2.makeSound();
		
		std::cout << std::endl << "--- Destructors (leaving scope) ---" << std::endl;
	}

	std::cout << std::endl << "=== TEST 6: Cat deep copy tests ===" << std::endl;
	{
		Cat cat1;
		Cat cat2 = cat1; // Copy constructor
		Cat cat3;
		cat3 = cat1; // Assignment operator
		
		std::cout << std::endl << "--- All cats making sound ---" << std::endl;
		cat1.makeSound();
		cat2.makeSound();
		cat3.makeSound();
		
		std::cout << std::endl << "--- Destructors (leaving scope) ---" << std::endl;
	}

	std::cout << std::endl << "=== All tests completed ===" << std::endl;
	return 0;
}
