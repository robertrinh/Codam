/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 14:51:08 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/11 14:58:31 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
private:
	std::string _ideas[100];
	
public:
	Brain();
	~Brain();
	Brain(const Brain& src);
	Brain& operator=(const Brain& src);
	
};