/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/18 19:16:25 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/21 13:07:12 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string _type;

public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	
	//returns const + const and end does not modify member variables of class
	const std::string& getType() const; 
	void setType(std::string type);	
};

#endif