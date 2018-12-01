// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Account.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/18 18:22:51 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/18 18:22:51 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Account.class.hpp"
#include <iostream>
#include <ctime>

int		Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}
int		Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}
int		Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout	<< " accounts:" << Account::_nbAccounts
				<< ";total:" << Account::_totalAmount
				<< ";deposits:" << Account::_totalNbDeposits
				<< ";withdrawals:" << Account::_totalNbWithdrawals
				<< std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";created" << std::endl;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	return ;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed" << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount = this->_amount;

	this->_nbDeposits += 1;
	this->_amount += deposit;
	Account::_displayTimestamp();
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	std::cout	<< " index:" << this->_accountIndex
				<< ";p_amount:" << p_amount
				<< ";deposit:" << deposit
				<< ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount = this->_amount;

	Account::_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";p_amount:" << p_amount
				<< ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;
	std::cout	<< withdrawal
				<< ";amount:" << this->_amount
				<< ";nb_withdrawals:" << this->_nbWithdrawals
				<< std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	time_t	now = time(0);

	tm *ltm = localtime(&now);
	std::cout << "[" << 1900 + ltm->tm_year
					 << ((1 + ltm->tm_mon < 10) ? "0" : "") << 1 + ltm->tm_mon
					 << ((ltm->tm_mday < 10) ? "0" : "") << ltm->tm_mday
					 << "_"
					 << ((ltm->tm_hour < 10) ? "0" : "") << ltm->tm_hour
					 <<	((ltm->tm_min < 10) ? "0" : "") << ltm->tm_min
					 <<	((ltm->tm_sec < 10) ? "0" : "") << ltm->tm_sec
					 << "]";
}

Account::Account(void) : _accountIndex(Account::_nbAccounts),
										_amount(0),
										_nbDeposits(0),
										_nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";created" << std::endl;
	Account::_nbAccounts += 1;
	return ;
}
