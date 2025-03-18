/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:36:53 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/18 14:00:40 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete i;
		delete j;
		delete meta;
	}
	{
		std::cout << std::endl;
		const WrongAnimal* wronganimal = new WrongAnimal();
		const WrongAnimal* wrongcat = new WrongCat();
		std::cout << wronganimal->getType() << " " << std::endl;
		std::cout << wrongcat->getType() << " " << std::endl;
		wronganimal->makeSound();
		std::cout << "cannot make a cat sound incoming:" << std::endl;
		wrongcat->makeSound();
		delete wronganimal;
		delete wrongcat;
	}

	return 0;
}