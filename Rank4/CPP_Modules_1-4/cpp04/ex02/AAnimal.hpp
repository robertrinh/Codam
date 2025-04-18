/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:37:09 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/13 17:42:39 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string _type;

public:
	AAnimal();
	virtual ~AAnimal();
	AAnimal(const AAnimal &src);
	AAnimal &operator=(const AAnimal &src);

	const std::string &getType() const;
	void setType(const std::string &type);
	virtual void makeSound() const = 0; //* pure virtual function for abstract class
};

#endif

//* instantiating -> creating object for the class
//* by making it abstract, you cannot declare AAnimal aanimal in main, because it cannot instantiate abstract class
//* specifically used as a base class for derived classes