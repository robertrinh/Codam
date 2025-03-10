/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:37:09 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/10 17:50:56 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	~Animal();
	Animal(const Animal& src);
	Animal& operator=(const Animal& src);

	const std::string& getType() const;
	void makeSound();
};

#endif