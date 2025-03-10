/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/18 14:20:38 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/10 13:17:15 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "Ready for some textury brains?" << std::endl;
	std::cout << "Michael on the STACK!!" << std::endl;
	Zombie zombie("Michael");
	zombie.announce();

	std::cout << std::endl;
	std::cout << "Jackson on the HEAP, hee-hee" << std::endl;
	Zombie* ptr_zombie = newZombie("Jackson");
	if (!ptr_zombie)
		return 1;
	ptr_zombie->announce();
	delete ptr_zombie;
	
	std::cout << std::endl;
	std::cout << "Random brudda getting money from the music set" << std::endl;
	std::cout << "Because it is a thriller!! thriller at niiiight" << std::endl;
	randomChump("Figurant");

	std::cout << std::endl;
	return 0;
}