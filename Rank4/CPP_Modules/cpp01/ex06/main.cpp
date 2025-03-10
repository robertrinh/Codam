/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/21 17:49:47 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/10 12:20:02 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl dude;
		dude.complain(argv[1]);
	}
	else
	{
		std::cerr << "You just don't want to hear Harl complain, huh?" << std::endl;
		std::cerr << "try either of these commands: {DEBUG} {INFO} {WARNING} {ERROR}" << std::endl;
		return 1;
	}
	return 0;
}