/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/18 14:44:14 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/11 12:53:20 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief created new zombie, allocated on the heap
 * @return pointer to object of type Zombie
 */
Zombie* newZombie(std::string name)
{
	Zombie* ptr_zombie = new Zombie(name);
	return ptr_zombie;
}
