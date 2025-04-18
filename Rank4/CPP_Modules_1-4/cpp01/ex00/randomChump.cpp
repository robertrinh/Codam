/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/18 14:53:06 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/18 14:54:43 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief creates new random zombie, allocated on the stack
 * @brief announces itself
 */
void randomChump(std::string name)
{
	Zombie random_zombie = Zombie(name);
	random_zombie.announce();
}
