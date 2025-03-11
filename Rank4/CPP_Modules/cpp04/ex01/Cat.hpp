/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:37:30 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/11 15:00:55 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* _brain;
public:
	Cat();
	~Cat();
	Cat(const Cat& src);
	Cat& operator=(const Cat& src);

	void makeSound() const; //* Overrides base class' implementation
};

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat& src);
	WrongCat& operator=(const WrongCat& src);

	void makeSound() const;
};
