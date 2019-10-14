#ifndef ACCOUNT_CLASS_CPP
#define ACCOUNT_CLASS_CPP
// clang++ -std=c++98 -Wall -Wextra -Werror Account.class.cpp tests.cpp Account.class.hpp
#include "Account.class.hpp"
#include <iostream>

Account::Account( int initial_deposit )
{
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << "index:" ;
	std::cout << this->_accountIndex ;
	std::cout << ";amount:" ;
	std::cout << initial_deposit ;
	std::cout << ";created" ;
	std::cout << std::endl ;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" ;
	std::cout << this->_accountIndex ;
	std::cout << ";amount:" ;
	std::cout << this->_amount ;
	std::cout << ";closed" ;
	std::cout << std::endl ;
}

int	Account::getNbAccounts( void )
{
	std::cout << "_nbAccounts:";
	std::cout << _nbAccounts;
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	std::cout << "getTotalAmount:";
	std::cout << Account::_totalAmount;
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:";
	std::cout << _nbAccounts;
	std::cout << ";total:";
	std::cout << _totalAmount;
	std::cout << ";deposits:";
	std::cout << Account::getNbDeposits();
	std::cout << ";withdrawals:";
	std::cout << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	this->_amount += deposit;
	this->_nbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";p_amount:";
	std::cout << this->_amount - deposit;
	std::cout << ";deposit:";
	std::cout << deposit;
	std::cout << ";amount:";
	std::cout << this->_amount;
	std::cout << ";nb_deposits:";
	std::cout << this->_nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";p_amount:";
	std::cout << this->_amount;
	std::cout << ";withdrawal:";

	if (withdrawal <= this->_amount)
	{
		Account::_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		this->_totalNbWithdrawals++;

		std::cout << withdrawal;
		std::cout << ";amount:";
		std::cout << this->_amount;
		std::cout << ";nb_withdrawals:";
		std::cout << this->_nbWithdrawals;
		std::cout << std::endl;
		return 0;
	}
	else
	{
		std::cout << "refused";
		std::cout << std::endl;
		return 1;
	}
}

int		Account::checkAmount( void ) const
{
	static unsigned int call_count = 0;
	call_count++;

	return Account::_amount;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:";
	std::cout << this->_amount;
	std::cout << ";deposits:";
	std::cout << this->_nbDeposits;
	std::cout << ";withdrawals:";
	std::cout << this->_nbWithdrawals;
	std::cout << std::endl;

}

void	Account::_displayTimestamp( void )
{
	std::cout << "[_displayTimestamp] ";
}

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

#endif
