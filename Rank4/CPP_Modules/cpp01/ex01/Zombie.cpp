/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/18 14:38:58 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/18 15:15:21 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "NAMELESS zombie has arrived from the dead (void constructor)" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Zombie " << this->_name << " has arrived from the dead" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " has perished" << std::endl;
	return ;
}

void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::SetName(const std::string& name)
{
	this->_name = name;
}
