/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:37:30 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/21 11:47:52 by qtrinh        ########   odam.nl         */
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

	void makeSound() const override; //* Overrides base class' implementation
	void setIdeas(int index, const std::string& idea);
	std::string& getIdeas(int index) const;
};

