/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/18 14:21:32 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/18 14:51:10 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string _name;

public:
	Zombie(std::string name);
	~Zombie();
	
	void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif