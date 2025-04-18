/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:36:53 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/13 17:46:45 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		const AAnimal *j = new Dog();
		const AAnimal *i = new Cat();
		delete j;
		delete i;
	}
	std::cout << std::endl;
	std::cout << "own tests:" << std::endl;
	{
		const int size = 4;
		AAnimal *aanimals[size];

		std::cout << "filling AAnimal array with 2 dogs and 2 cats" << std::endl;
		for (int i = 0; i < size / 2; i++) //* first half fill
			aanimals[i] = new Dog();
		for (int i = size / 2; i < size; i++) //* second half fill
			aanimals[i] = new Cat();

		std::cout << std::endl
				  << "noisemaking..." << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << aanimals[i]->getType() << ": ";
			aanimals[i]->makeSound();
		}
		for (int i = 0; i < size; i++)
			delete aanimals[i];
	}
	{
		std::cout << std::endl
				  << "test: Copy constructor" << std::endl;
		Cat cat;
		Cat fakeCat(cat);	//* fakeCat created + init using existing cat
		Cat fakerCat = cat; //* fakerCat created + init same line by calling existing cat
		std::cout << "Cat type: " << cat.getType();
		std::cout << " and also makes the following sound: ";
		cat.makeSound();

		std::cout << "fakeCat type: " << fakeCat.getType();
		std::cout << " and also makes the following sound: ";
		fakeCat.makeSound();

		std::cout << "fakerCat type: " << fakerCat.getType();
		std::cout << " and also makes the following sound: ";
		fakerCat.makeSound();
	}
	{
		std::cout << std::endl
				  << "test: deep copies with Copy Assignment Operator" << std::endl;
		Dog ogDog;
		Dog fakeDawg;
		fakeDawg = ogDog; //* object already created, assigning afterwards to trigger CAO

		std::cout << "ogDog type: " << ogDog.getType();
		std::cout << ", fakeDawg type: " << fakeDawg.getType();
		fakeDawg.setType("Crip");
		std::cout << std::endl
				  << "changing up fakeDawg to check copy.." << std::endl;
		std::cout << "ogDog type: " << ogDog.getType();
		std::cout << ", fakeDawg type: " << fakeDawg.getType();
		std::cout << std::endl;
	}
	{
		std::cout << std::endl
				  << "test: printing catdog ideas from brain" << std::endl;
		Cat *cat = new Cat();

		for (int i = 0; i < 100; i++)
		{
			if (i % 2 == 0)
				cat->setIdeas(i, "fish...");
			else
				cat->setIdeas(i, "prey...");
		}
		for (int i = 0; i < 6; i++)
			std::cout << cat->getIdeas(i) << std::endl;
		delete cat;

		std::cout << std::endl;
		Dog *dog = new Dog();
		for (int i = 0; i < 100; i++)
		{
			if (i % 2 == 0)
				dog->setIdeas(i, "bork...");
			else
				dog->setIdeas(i, "BARK...");
		}
		for (int i = 0; i < 6; i++)
			std::cout << dog->getIdeas(i) << std::endl;
		delete dog;
	}
	{
		std::cout << std::endl
				  << "testing DEEP copying catdog, with ideas from brain" << std::endl;
		Dog dawg;
		for (int i = 0; i < 100; i++)
			dawg.setIdeas(i, "BONE.. (THUG N HARMONY)");
		for (int i = 0; i < 6; i++)
			dawg.getIdeas(i);

		Dog anotha_dawg;
		anotha_dawg = dawg;
		std::cout << "the og dawg is placing copyright on" << std::endl;
		for (int i = 0; i < 4; i++)
			std::cout << dawg.getIdeas(i) << std::endl;
		std::cout << "but anotha dawg is copying his shi!!" << std::endl;
		for (int i = 0; i < 4; i++)
			std::cout << anotha_dawg.getIdeas(i) << std::endl;

		if (&dawg.getIdeas(0) == &anotha_dawg.getIdeas(0))
			std::cout << "Shallow copy.. you better dive in deep" << std::endl;
		else
			std::cout << "You deep copied!! look at you champ" << std::endl;
		std::cout << "address of dawg: " << &dawg.getIdeas(0) << std::endl;
		std::cout << "address of anotha_dawg: " << &anotha_dawg.getIdeas(0) << std::endl;
	}
	{
		// AAnimal aanimal; //<-- will give compiling error because cannot be instantiated because of the virtual void
	}
	return 0;
}

//* deep copy vs shallow copy -> in notion
//* write down theory when deleting ''existing'' brain regrarding = operator
//* difference between copy constructor and copy assignment operator