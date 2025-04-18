/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 13:45:32 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/20 13:16:29 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap //* virtual inheritance: only makes use of 1 ClapTrap 
{
protected:
	const int _fragHP = 100;
	const int _fragAD = 30;
public:
	FragTrap();
	FragTrap(std::string const &name);
	FragTrap(const FragTrap &src);
	FragTrap &operator=(const FragTrap &src);
	~FragTrap();

	void highFivesGuys();
};
