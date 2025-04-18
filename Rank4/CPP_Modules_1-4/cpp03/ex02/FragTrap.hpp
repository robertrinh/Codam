/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 13:45:32 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/18 12:07:57 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string const& name);
	FragTrap(const FragTrap& src);
	FragTrap &operator=(const FragTrap& src);
	~FragTrap();

	void highFivesGuys();
};
