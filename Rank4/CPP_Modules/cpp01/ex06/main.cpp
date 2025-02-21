/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/21 17:49:47 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/21 17:51:42 by robertrinh    ########   odam.nl         */
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
		std::cout << "You just don't want to hear Harl complain huh" << std::endl;
		return 1;
	}
	return 0;
}