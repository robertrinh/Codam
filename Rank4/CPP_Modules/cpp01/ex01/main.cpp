/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/18 15:15:54 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/10 11:54:35 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "1 brain is not enough for a HORDE of zombies....???" << std::endl;
	Zombie* horde = zombieHorde(5, "Hoarder");
	if (!horde)
		return 1;
	std::cout << std::endl;
	std::cout << "A huge horde of 5 named Hoarders are coming in hot!!" << std::endl;
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	std::cout << std::endl;
	delete[] horde;
	return 0;
}
