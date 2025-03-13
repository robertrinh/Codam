/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:37:09 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/13 14:59:15 by robertrinh    ########   odam.nl         */
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
	virtual ~Animal();
	Animal(const Animal& src);
	Animal& operator=(const Animal& src);

	const std::string& getType() const;
	void setType(const std::string& type);
	virtual void makeSound() const; //* virtual void to allow derived class override with own implementation
};

#endif