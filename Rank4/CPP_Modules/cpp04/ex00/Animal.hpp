/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:37:09 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/11 13:49:41 by qtrinh        ########   odam.nl         */
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
	virtual void makeSound() const; //* virtual void to allow derived class override with own implementation
};

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal& src);
	WrongAnimal& operator=(const WrongAnimal& src);

	const std::string& getType() const;
	virtual void makeSound() const;
};

#endif