/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/21 16:30:59 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/10 13:23:31 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

enum level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

Harl::Harl()
{}

Harl::~Harl()
{}

void Harl::_debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::_info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month" << std::endl;
}

void Harl::_error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int Harl::getLevel(const std::string& level)
{
	if (level == "DEBUG") 
		return DEBUG;
	if (level == "INFO") 
		return INFO;
	if (level == "WARNING") 
		return WARNING;
	if (level == "ERROR") 
		return ERROR;
	return -1;
}

void Harl::complain(std::string level)
{
	void (Harl::*functions[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	
	int loglevel = getLevel(level);
	switch (loglevel)
	{
		case DEBUG:
			(this->*functions[0])();
		case INFO:
			(this->*functions[1])();
		case WARNING:
			(this->*functions[2])();
		case ERROR:
			(this->*functions[3])();
			break ;
		default:
			std::cout << "Harl does not comprehend what you are doing." << std::endl;
			break ;		
	}
}
