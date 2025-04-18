/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/18 19:30:07 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/21 13:09:40 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"
class HumanB
{
private:
	std::string _name;
	Weapon *_weapon;

public:
	HumanB(std::string _name);
	~HumanB();

	void setWeapon(Weapon &weapon);
	void attack();
};

#endif