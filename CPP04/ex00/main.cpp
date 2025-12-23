/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:39:54 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 14:09:19 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal/Animal.hpp"
#include "Animal/Dog/Dog.hpp"
#include "Animal/Cat/Cat.hpp"
#include "WrongAnimal/WrongAnimal.hpp"
#include "WrongAnimal/WrongCat/WrongCat.hpp"

int main()
{
    std::cout << "=== CORRECT POLYMORPHISM ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl << "--- Types ---" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << std::endl << "--- Sounds ---" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl << "--- Cleanup ---" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << std::endl << "=== WRONG POLYMORPHISM ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << std::endl << "--- Types ---" << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;

    std::cout << std::endl << "--- Sounds (WrongCat uses WrongAnimal sound) ---" << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();

    std::cout << std::endl << "--- Cleanup ---" << std::endl;
    delete wrongMeta;
    delete wrongCat;

    std::cout << std::endl << "=== ADDITIONAL TESTS ===" << std::endl;
    Dog dog1;
    Dog dog2("Buddy");
    Cat cat1;
    Cat cat2("Whiskers");

    std::cout << std::endl << "--- Direct calls ---" << std::endl;
    dog1.makeSound();
    dog2.makeSound();
    cat1.makeSound();
    cat2.makeSound();

    return 0;
}
