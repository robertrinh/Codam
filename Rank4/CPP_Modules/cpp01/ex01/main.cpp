/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/18 15:15:54 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/18 15:21:33 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "1 brain is not enough for a HORDE of zombies....???" << std::endl;
	Zombie* horde = zombieHorde(5, "Hoarder");
	std::cout << "A huge horde of 5 named Hoarders are coming in hot!!" << std::endl;
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
