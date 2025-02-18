/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 18:46:59 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/18 13:03:36 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//* constructor
Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

//* destructor
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

// * getter functions
int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << \
	";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	this->_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << ";amount:" << this->_amount<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount() const
{
	return this->_amount;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << \
	";withdrawals:" << this->_nbWithdrawals << std::endl;
}

/**
 * @brief displays timestamp in the format [YYYYMMDD_HHMMSS]
 * @details uses time_t to hold number of sec since 1-1-1970
 * @details time(0) gets the current time
 * @details tm* tm = localtime(&t) converts the time into a tm structure
 * @details strftime formats the time into a string
 */
void	Account::_displayTimestamp()
{
	std::time_t t = std::time(0);
	std::tm* tm = std::localtime(&t);
	char buff[20];
	strftime(buff, 20, "[%Y%m%d_%H%M%S] ", tm);
	std::cout << buff;
}

/*
  if you want to compare using diff cmd
*/
// void	Account::_displayTimestamp( void )
// {
// 	std::cout << "[19920104_091532] ";
// }