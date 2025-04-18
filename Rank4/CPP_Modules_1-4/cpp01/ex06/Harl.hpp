/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/21 16:28:44 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/21 18:00:11 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
private:
	void _debug();
	void _info();
	void _warning();
	void _error();
public:
	Harl();
	~Harl();
	
	void complain(std::string level);
	int getLevel(const std::string& level);
};

#endif