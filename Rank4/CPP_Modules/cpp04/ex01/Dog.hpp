/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:37:30 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/21 11:48:00 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* _brain;
public:
	Dog();
	~Dog();
	Dog(const Dog& src);
	Dog& operator=(const Dog& src);

	void makeSound() const override; //* Overrides base class' implementation
	void setIdeas(int index, const std::string& idea);
	std::string& getIdeas(int index) const;
};
