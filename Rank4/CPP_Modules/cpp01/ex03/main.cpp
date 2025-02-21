/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/19 13:33:48 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/19 16:04:39 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
	  Weapon club = Weapon("crude spiked club");
	  HumanA bob("Bob", club);
	  bob.attack();
	  club.setType("some other type of club");
	  bob.attack();
  } 
  return 0;
}

