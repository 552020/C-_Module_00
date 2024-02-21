#include "Account.hpp"
#include <iomanip>
#include <iostream>

// Initialize static members
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
// Initialize the static collection of Account pointers
std::vector<Account *> Account::_accounts;

int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals()
			  << std::endl;

	for (std::vector<Account *>::iterator it = Account::_accounts.begin(); it != Account::_accounts.end(); ++it)
	{
		(*it)->displayStatus();
	}
}

void Account::_displayTimestamp()
{
	// Obtain current time in seconds
	std::time_t currentTime = std::time(nullptr);

	// Convert to local time and store in a tm structure
	std::tm *localTime = std::localtime(&currentTime);

	// Display timestamp in the format [YYYYMMDD_HHMMSS]
	std::cout << '[' << std::setfill('0') << std::setw(4) << (localTime->tm_year + 1900) << std::setw(2)
			  << (localTime->tm_mon + 1) << std::setw(2) << localTime->tm_mday << '_' << std::setw(2)
			  << localTime->tm_hour << std::setw(2) << localTime->tm_min << std::setw(2) << localTime->tm_sec << "] ";
}

Account::Account(int initial_deposit)
	: _accountIndex(Account::_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{

	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int Account::checkAmount(void) const { return this->_amount; }

void Account::makeDeposit(int deposit)
{

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;

	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

void Account::displayStatus(void) const
{

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}