/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 14:51:08 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/13 17:09:52 by robertrinh    ########   odam.nl         */
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
	Brain(const Brain& src);
	Brain& operator=(const Brain& src);
	~Brain();
	
	std::string& getIdea(int index);
	void setIdea(int index, const std::string& idea);
};