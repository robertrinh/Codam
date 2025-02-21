/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/21 17:43:19 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/21 17:47:26 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl dude;

	dude.complain("DEBUG");
	dude.complain("INFO");
	dude.complain("WARNING");
	dude.complain("ERROR");
	dude.complain("About what though");
	return 0;
}
