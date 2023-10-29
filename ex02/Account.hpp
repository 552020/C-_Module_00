// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

#include <vector>

class Account {

public:
  typedef Account t;

  // get the number of accounts
  static int getNbAccounts(void);
  // get the total amount of deposits
  static int getTotalAmount(void);
  // get the total number of deposits
  static int getNbDeposits(void);
  // get the total number of withdrawals
  static int getNbWithdrawals(void);
  // display the accounts informations
  static void displayAccountsInfos(void);

  Account(int initial_deposit);
  ~Account(void);

  void makeDeposit(int deposit);
  bool makeWithdrawal(int withdrawal);
  int checkAmount(void) const;
  void displayStatus(void) const;

private:
  static int _nbAccounts;
  static int _totalAmount;
  static int _totalNbDeposits;
  static int _totalNbWithdrawals;
  // we need to store the accounts somewhere
  // since displayAccountsInfos() is a static method
  // and it doesn't take any arguments
  static std::vector<Account *> _accounts;

  static void _displayTimestamp(void);

  int _accountIndex;
  int _amount;
  int _nbDeposits;
  int _nbWithdrawals;

  Account(void);
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif /* __ACCOUNT_H__ */
