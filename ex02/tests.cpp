// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main(void)
{
	// New type for a vector of Account pointers
	typedef std::vector<Account::t> accounts_t;
	// New type for a vector of ints
	typedef std::vector<int> ints_t;
	// New type for a pair of iterators
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	/* CREATE THE ACCOUNTS */
	// We create an array of amounts
	int const amounts[] = {42, 54, 957, 432, 1234, 0, 754, 16576};
	// We calculate the size of the array
	size_t const amounts_size(sizeof(amounts) / sizeof(int));
	std::cout << "sizeof(amounts): " << sizeof(amounts) << std::endl;
	std::cout << "sizeof(int): " << sizeof(int) << std::endl;
	std::cout << "amounts_size: " << amounts_size << std::endl;
	std::cout << "pointer to amounts: " << amounts << std::endl;
	std::cout << "pointer to amounts + amounts_size: " << amounts + amounts_size << std::endl;
	// We create a vector of Accounts not of Account pointers
	// we use the constructor that takes two iterators
	// This work because the Account class has a constructor that takes an int
	accounts_t accounts(amounts, amounts + amounts_size);
	accounts_t::iterator acc_begin = accounts.begin();
	accounts_t::iterator acc_end = accounts.end();
	std::cout << "after account initialization" << std::endl;

	// We create an array of deposits
	int const d[] = {5, 765, 564, 2, 87, 23, 9, 20};
	// We calculate the size of the array: how many elements in the array
	size_t const d_size(sizeof(d) / sizeof(int));
	// We create a vector of ints (deposits)
	ints_t deposits(d, d + d_size);
	ints_t::iterator dep_begin = deposits.begin();
	ints_t::iterator dep_end = deposits.end();

	// We create an array of withdrawals
	int const w[] = {321, 34, 657, 4, 76, 275, 657, 7654};
	size_t const w_size(sizeof(w) / sizeof(int));
	// We create a vector of ints (withdrawals)
	ints_t withdrawals(w, w + w_size);
	ints_t::iterator wit_begin = withdrawals.begin();
	ints_t::iterator wit_end = withdrawals.end();

	// We display the accounts
	std::cout << "displayAccountsInfos" << std::endl;
	Account::displayAccountsInfos();
	std::cout << "displayStatus - for each" << std::endl;
	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));
	std::cout << "before for loop" << std::endl;
	std::cout << "do the deposits" << std::endl;
	for (acc_int_t it(acc_begin, dep_begin); it.first != acc_end && it.second != dep_end; ++(it.first), ++(it.second))
	{

		(*(it.first)).makeDeposit(*(it.second));
	}
	std::cout << "displayAccountsInfos" << std::endl;

	Account::displayAccountsInfos();
	std::cout << "displayStatus - for each" << std::endl;
	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

	for (acc_int_t it(acc_begin, wit_begin); it.first != acc_end && it.second != wit_end; ++(it.first), ++(it.second))
	{

		(*(it.first)).makeWithdrawal(*(it.second));
	}

	Account::displayAccountsInfos();
	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

	return 0;
}

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
