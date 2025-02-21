/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/18 19:16:25 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/18 19:28:48 by robertrinh    ########   odam.nl         */
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
	~Weapon();
	
	//returns const + const and end does not modify member variables of class
	const std::string& GetType() const; 
	void SetType(std::string type);	
};

#endif